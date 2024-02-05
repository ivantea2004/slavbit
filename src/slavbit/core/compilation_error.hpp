#pragma once
#include <stdexcept>

namespace slavbit::core
{

	class compilation_error : std::runtime_error
	{
	public:
		compilation_error() : std::runtime_error("") {}
	};

}