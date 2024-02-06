#include <slavbit/parser/unexpected_token_error.hpp>

namespace slavbit::parser
{

	unexpected_token_error::unexpected_token_error(core::location location, expectable expected) :
		core::syntex_error(location),
		expected_(expected)
	{}
	std::string unexpected_token_error::error_text() const
	{
		return "unexpected token, expected " + to_string(expected_);
	}

}