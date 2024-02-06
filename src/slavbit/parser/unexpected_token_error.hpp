#pragma once
#include <slavbit/core/syntax_error.hpp>
#include <slavbit/parser/expectable.hpp>

namespace slavbit::parser
{

	class unexpected_token_error : public core::syntex_error
	{
	public:
		unexpected_token_error(core::location location, expectable expected);
		std::string error_text() const override;
	private:
		expectable expected_;
	};

}