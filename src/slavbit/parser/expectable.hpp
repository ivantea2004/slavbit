#pragma once
#include <string>

namespace slavbit::parser
{

	enum class expectable
	{
		type_name
	};

	std::string to_string(expectable);

}