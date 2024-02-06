#pragma once
#include <string>

namespace slavbit::lexer
{

	enum class bracket
	{
		open_paren,
		close_paren,
		open_curve,
		close_curve,
		open_square,
		close_square
	};

	bool from_string(std::string_view, bracket&);
	std::string to_string(bracket);

}