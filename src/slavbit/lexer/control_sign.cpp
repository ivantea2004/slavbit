#include <slavbit/lexer/control_sign.hpp>

namespace slavbit::lexer
{

	bool from_string(std::string_view s, control_sign& c)
	{
		using enum control_sign;
		if (s == ",")
		{
			c = comma;
			return true;
		}
		if (s == ":")
		{
			c = colon;
			return true;
		}
		if (s == ";")
		{
			c = semicolon;
			return true;
		}
		return false;
	}
	std::string to_string(control_sign c)
	{
		using enum control_sign;
		switch (c)
		{
		case comma: return ",";
		case colon: return ":";
		case semicolon: return ";";
		default: return "";
		}
	}

	bool from_string(std::string_view s, bracket& b)
	{
		using enum bracket;
		if (s == "(")
		{
			b = open_paren;
			return true;
		}
		if (s == ")")
		{
			b = close_paren;
			return true;
		}
		if (s == "[")
		{
			b = open_square;
			return true;
		}
		if (s == "]")
		{
			b = close_square;
			return true;
		}
		if (s == "{")
		{
			b = open_curve;
			return true;
		}
		if (s == "}")
		{
			b = close_curve;
			return true;
		}
		return false;
	}
	std::string to_string(bracket b)
	{
		using enum bracket;
		switch (b)
		{
		case open_curve: return "{";
		case close_curve: return "}";
		case open_paren: return "(";
		case close_paren: return ")";
		case open_square: return "[";
		case close_square: return "]";
		default: return "";
		}
	}

	bool from_string(std::string_view s, keyword& k)
	{
		using enum keyword;
		if (s == "function")
		{
			k = function;
			return true;
		}
		if (s == "let")
		{
			k = let;
			return true;
		}
		return false;
	}
	std::string to_string(keyword k)
	{
		using enum keyword;
		switch (k)
		{
		case function: return "function";
		case let: return "let";
		default: return "";
		}
	}

}