#include <slavbit/core/unexpected_end_error.hpp>

namespace slavbit::core
{

	std::string unexpected_end_error::error_text() const
	{
		return "unexpected end";
	}

}