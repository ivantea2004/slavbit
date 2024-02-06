#include <slavbit/lexer/unexpected_char_error.hpp>

namespace slavbit::lexer
{

	unexpected_char_error::unexpected_char_error(core::location location, char unexpected) :
		core::lexical_error(location),
		unexpected_(unexpected)
	{}
	std::string unexpected_char_error::error_text() const
	{
		return std::string("unexpected char '") + unexpected_ + "'";
	}

}