#pragma once
#include <string>

namespace slavbit::core
{

	struct source_code
	{
		std::string_view file_name;
		std::string_view text;
	};

}