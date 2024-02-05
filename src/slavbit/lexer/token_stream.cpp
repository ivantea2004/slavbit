#include <span>
#include <cassert>
#include <algorithm>
#include <slavbit/core/compilation_error.hpp>
#include <slavbit/lexer/token_stream.hpp>

namespace slavbit::lexer
{

	token_stream::token_stream(core::source_code code) :
		code_(code),
		offset_(0),
		buffered_token_{},
		did_unget_(false)
	{}

	bool token_stream::is_word_char(char x)
	{
		return std::isalnum(x);
	}

	std::optional<token> token_stream::get()
	{
		if (did_unget_)
		{
			did_unget_ = false;
			return buffered_token_;
		}
		else
		{
			auto tok = parse_token();
			if (tok)
			{
				return buffered_token_ = *tok;
			}
			else
			{
				return std::nullopt;
			}
		}
	}

	void token_stream::unget()
	{
		assert(!did_unget_);
		did_unget_ = true;
	}

	bool token_stream::end()
	{
		if (get())
		{
			unget();
			return false;
		}
		return true;
	}

	std::optional<token> token_stream::parse_token()
	{
		auto& source = code_.text;
		while (offset_ < source.size() && isspace(source[offset_]))
		{
			offset_++;
		}
		if (offset_ == source.size())
		{
			return std::nullopt;
		}
		if (source[offset_] == '"')
		{
			return parse_string();
		}
		if (isdigit(source[offset_]))
		{
			return parse_number();
		}
		if (is_word_char(source[offset_]))
		{
			return parse_word();
		}
		return parse_sign();
	}

	bool token_stream::do_parse_bin(std::string_view s, token& t)
	{
		bool matched = false;
		lang::binary_arithmetic_operator op;
		if (from_string(s, op, true))
		{
			t.assign_ = op;
			matched = true;
		}
		if (from_string(s, op, false))
		{
			t.bin_arithm_ = op;
			matched = true;
		}
		return matched;
	}

	bool token_stream::do_parse_un(std::string_view s, token& t)
	{
		lang::unary_arithmetic_operator op;
		if (from_string(s, op))
		{
			t.un_arithm_ = op;
			return true;
		}
		return false;
	}

	bool token_stream::do_parse_control(std::string_view s, token& t)
	{
		control_sign c;
		if (from_string(s, c))
		{
			t.control_ = c;
			return true;
		}
		return false;
	}

	bool token_stream::do_parse_bracket(std::string_view s, token& t)
	{
		bracket b;
		if (from_string(s, b))
		{
			t.bracket_ = b;
			return true;
		}
		return false;
	}

	bool token_stream::do_parse_sign(size_t size, token& tok)
	{
		bool (*funcs[])(std::string_view, token&) = {
			do_parse_bin,
			do_parse_un,
			do_parse_control,
			do_parse_bracket
		};

		bool results[std::size(funcs)] = {};

		auto& source = code_.text;
		if (offset_ + size > source.size())
			return false;
		std::string_view cut{ source.begin() + offset_, source.begin() + offset_ + size };
		for (size_t i = 0; i < std::size(funcs); i++)
		{
			results[i] = funcs[i](cut, tok);
		}
		if (std::count(std::begin(results), std::end(results), true) > 0)
		{
			
			offset_ += size;
			return true;
		}
		else
		{
			return false;
		}
	}

	token token_stream::parse_sign()
	{
		token out;
		if (do_parse_sign(3, out) || do_parse_sign(2, out), do_parse_sign(1, out))
		{
			return out;
		}
		throw core::compilation_error();
	}

	token token_stream::parse_string()
	{
		auto& source = code_.text;
		auto begin = source.begin() + offset_;
		offset_++;
		while (offset_ < source.size() && source[offset_] != '"')
		{
			offset_++;
		}
		if (offset_ == source.size())
		{
			throw core::compilation_error();
		}
		offset_++;
		auto end = source.begin() + offset_;
		token out;
		out.str_ = std::string_view{ begin, end };
		return out;
	}

	token token_stream::parse_number()
	{
		auto source = code_.text;
		auto begin = source.begin() + offset_;
		while (offset_ < source.size() && isdigit(source[offset_]))
		{
			offset_++;
		}
		auto end = source.begin() + offset_;
		if (end == source.end() || !is_word_char(*end))
		{
			token out;
			out.number_ = std::string_view{ begin, end };
			return out;
		}
		throw core::compilation_error();
	}

	std::string_view token_stream::do_parse_word()
	{
		auto& source = code_.text;
		auto begin = source.begin() + offset_;
		while (offset_ < source.size() && isalnum(source[offset_]))
		{
			offset_++;
		}
		auto end = source.begin() + offset_;
		return { begin, end };
	}

	token token_stream::parse_word()
	{
		std::string_view word = do_parse_word();
		token out;
		keyword key;
		if (from_string(word, key))
			out.keyword_ = key;
		else
			out.id_ = word;
		return out;
	}

}