#pragma once
#include <slavbit/core/source_code.hpp>
#include <slavbit/lexer/token.hpp>

namespace slavbit::lexer
{

	class token_stream
	{
	public:

		token_stream(core::source_code code);

		std::optional<token> get();
		void unget();
		bool end();

	private:

		std::string_view do_parse_word();
		token parse_word();

		token parse_string();
		token parse_number();

		token parse_sign();
		bool do_parse_sign(size_t size, token&);
		static bool do_parse_bin(std::string_view, token&);
		static bool do_parse_un(std::string_view, token&);
		static bool do_parse_control(std::string_view, token&);
		static bool do_parse_bracket(std::string_view, token&);

		std::optional<token> parse_token();

		static bool is_word_char(char);

		token buffered_token_;
		bool did_unget_;
		core::source_code code_;
		size_t offset_;
	};

}