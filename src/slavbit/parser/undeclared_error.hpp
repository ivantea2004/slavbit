#pragma once
#include <slavbit/core/syntax_error.hpp>

namespace slavbit::parser
{

	class undeclared_error : public core::syntex_error
	{
	public:
		undeclared_error(core::location location, std::string undeclared);

		std::string error_text() const override;
	private:
		std::string undeclared_;
	};

}