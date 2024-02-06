#include <slavbit/core/code_error.hpp>

namespace slavbit::core
{

	code_error::code_error(core::location location) :
		diagnostic_message(),
		std::runtime_error("Code error"),
		error_location(location)
	{}

	std::string code_error::text() const
	{
		return "error: " + error_text() + "\n" + error_body();
	}

	std::string code_error::error_body() const
	{
		return error_location.render(true);
	}

}