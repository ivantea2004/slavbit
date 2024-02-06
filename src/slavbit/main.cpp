#include <iostream>
#include <slavbit/lexer/token_stream.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/lang/variable_identifier.hpp>
#include <slavbit/lang/function_type.hpp>
#include <slavbit/parser/type.hpp>
#include <slavbit/core/compilation_error.hpp>

int main()
{
	using namespace slavbit;

	std::string code = "abc\nlol\n\n\n\n\n\n12 : 34\n\n\nlolkek\n123\n  {}\n"
		;
	
	{
		//core::line_iterator begin(code, 0), end(code, code.size());
		core::location begin({ code }, 0), end({ code }, code.size());
		core::location all(begin, end);
		std::cout << all.render(true);// << std::endl;
		std::cout << all.render(false);// << std::endl;

	}
	return 0;
	lexer::token_stream tokens({code});
	
	
	lang::scope global("", false, nullptr, nullptr);

	const lang::identifier_base* other;
	global.declare<lang::type_identifier>(other, "int", false, nullptr);
	
	global.declare<lang::scope>(other, "namespace", false, nullptr);

	try {
		core::diagnostic_stream ds;
		auto type = parser::parse_type(tokens, global, ds);

		//std::cout << type->to_string() << std::endl;
	}
	catch (const core::compilation_error& e)
	{
		std::cout << e.render_diagnostics();
	}
	return 0;
}