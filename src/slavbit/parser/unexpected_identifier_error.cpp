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
		return "unexpected identifier '" + unexpected_->full_name() + "', expected " + to_string(expected_);
	}

	std::string unexpected_identifier_error::error_body() const
	{
		return error_location.render(true) + "'" + unexpected_->full_name() + "' was declared as:\n" + unexpected_->declaration_location().render(true, '~');
	}

}