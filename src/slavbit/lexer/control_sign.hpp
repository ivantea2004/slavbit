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

	bool from_string(std::string_view, control_sign&);
	std::string to_string(control_sign);

}