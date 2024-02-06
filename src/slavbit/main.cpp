#include <iostream>
#include <slavbit/lexer/token_stream.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/lang/variable_identifier.hpp>
#include <slavbit/lang/global_scope.hpp>
#include <slavbit/parser/type.hpp>
#include <slavbit/core/code_error.hpp>

int main()
{
	using namespace slavbit;

	std::string code = "qwe abc";
	
	lexer::token_stream tokens({code});
	
	lang::global_scope global({});

	const lang::identifier_base* other;

	auto abc = global.declare<lang::variable_identifier>(other, "abc", false, nullptr, core::location({ code }, 4, 7));

	auto inner = global.declare<lang::scope>(other, "inner", false, nullptr, {});
	auto abc2 = inner->declare<lang::variable_identifier>(other, "abc2", false, nullptr, {});

	std::cout << abc->full_name() << std::endl;
	std::cout << abc2->full_name() << std::endl;

	core::diagnostic_stream ds;

	try {
		
		auto type = parser::parse_type(tokens, global, ds);

	}
	catch (const core::code_error& e)
	{
		ds.write(e);
	}
	return 0;
}