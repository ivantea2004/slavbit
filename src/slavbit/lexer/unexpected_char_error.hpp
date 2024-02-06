#pragma once
#include <slavbit/core/lexical_error.hpp>

namespace slavbit::lexer
{

	class unexpected_char_error : public core::lexical_error
	{
	public:
		unexpected_char_error(core::location location, char unexpected);
		std::string error_text() const override;
	private:
		char unexpected_;
	};

}