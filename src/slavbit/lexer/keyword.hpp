#pragma once
#include<string>

namespace slavbit::lexer
{

	enum class keyword
	{
		function,
		let
	};

	bool from_string(std::string_view, keyword&);
	std::string to_string(keyword);

}