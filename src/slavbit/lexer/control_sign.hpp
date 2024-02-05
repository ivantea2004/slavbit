#pragma once
#include <string>

namespace slavbit::lexer
{

	enum class control_sign
	{
		comma,
		colon,
		semicolon
	};

	enum class bracket
	{
		open_paren,
		close_paren,
		open_curve,
		close_curve,
		open_square,
		close_square
	};

	enum class keyword
	{
		function,
		let
	};


	bool from_string(std::string_view, control_sign&);
	std::string to_string(control_sign);

	bool from_string(std::string_view, bracket&);
	std::string to_string(bracket);

	bool from_string(std::string_view, keyword&);
	std::string to_string(keyword);

}