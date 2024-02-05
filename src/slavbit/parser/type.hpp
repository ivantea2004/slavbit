#pragma once
#include <slavbit/lang/scope.hpp>
#include <slavbit/lexer/token_stream.hpp>
#include <slavbit/core/diagnostic_stream.hpp>
#include <memory>

namespace slavbit::parser
{

	std::shared_ptr<lang::type_base> parse_type(
		lexer::token_stream&tokens,
		const lang::scope&scope,
		core::diagnostic_stream&ds
	);

}