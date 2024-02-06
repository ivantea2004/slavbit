#pragma once
#include <slavbit/core/syntax_error.hpp>
#include <slavbit/lang/identifier_base.hpp>
#include <slavbit/parser/expectable.hpp>

namespace slavbit::parser
{

	class unexpected_identifier_error : public core::syntex_error
	{
	public:

		unexpected_identifier_error(core::location location, const lang::identifier_base* unexpected, expectable expected);

		std::string error_text() const override;
		std::string error_body() const override;

	private:
		const lang::identifier_base* unexpected_;
		expectable expected_;
	};

}