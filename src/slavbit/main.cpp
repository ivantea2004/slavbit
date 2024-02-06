#include <iostream>
#include <slavbit/lexer/token_stream.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/lang/variable_identifier.hpp>
#include <slavbit/lang/function_type.hpp>
#include <slavbit/parser/type.hpp>
#include <slavbit/core/code_error.hpp>

int main()
{
	using namespace slavbit;

	std::string code = "qwe abc";
	
	lexer::token_stream tokens({code});
	
	lang::scope global("", false, nullptr, nullptr, {});

	const lang::identifier_base* other;
	global.declare<lang::type_identifier>(other, "int", false, nullptr, {});
	
	global.declare<lang::variable_identifier>(other, "abc", false, nullptr, core::location({ code }, 4, 7));

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