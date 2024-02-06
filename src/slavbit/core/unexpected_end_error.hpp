#pragma once
#include <slavbit/core/code_error.hpp>

namespace slavbit::core
{

	class unexpected_end_error : public code_error
	{
	public:
		using code_error::code_error;
		std::string error_text() const override;
	};

}