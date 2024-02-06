#include <slavbit/parser/unexpected_identifier_error.hpp>

namespace slavbit::parser
{

	unexpected_identifier_error::unexpected_identifier_error(core::location location, const lang::identifier_base* unexpected, expectable expected) :
		core::syntex_error(location),
		unexpected_(unexpected),
		expected_(expected)
	{}

	std::string unexpected_identifier_error::error_text() const
	{
		return "unexpected identifier '" + std::string(unexpected_->name()) + "', expected " + to_string(expected_);
	}

	std::string unexpected_identifier_error::error_body() const
	{
		return "'" + std::string(unexpected_->name()) + "' was declared as:\n" + unexpected_->declaration_location().render(true, '~');
	}

}