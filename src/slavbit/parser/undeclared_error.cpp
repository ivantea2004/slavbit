#include <slavbit/parser/undeclared_error.hpp>

namespace slavbit::parser
{

	undeclared_error::undeclared_error(core::location location, std::string undeclared) :
		core::syntex_error(location),
		undeclared_(undeclared)
	{}

	std::string undeclared_error::error_text() const
	{
		return "'" + undeclared_ + "' is not declared";
	}

}