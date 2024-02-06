#pragma once
#include <slavbit/core/code_error.hpp>

namespace slavbit::core
{

	class syntex_error : public code_error
	{
		using code_error::code_error;
	};

}