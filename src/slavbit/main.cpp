#include <iostream>
#include <slavbit/lexer/token_stream.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/lang/variable_identifier.hpp>
#include <slavbit/lang/function_type.hpp>

int main()
{
	using namespace slavbit;

	std::string code = R"(
	1 + 2 + 3 ; : L m ([[{}
)";
	
	lexer::token_stream tokens({code});
	
	
	lang::scope global("", false, nullptr, nullptr);

	const lang::identifier_base* other;
	auto int_type_id = global.declare<lang::type_identifier>(other, "int", false, nullptr);
	
	auto int_type = std::make_shared<lang::named_type>();

	int_type->id = int_type_id;

	auto var_a = global.declare<lang::variable_identifier>(other, "a", false, int_type);

	auto f_type = std::make_shared<lang::function_type>();
	f_type->return_type = int_type;

	auto var_b = global.declare<lang::variable_identifier>(other, "a", false, f_type);

	std::cout << int_type->to_string() << std::endl;

	while (true)
	{
		auto t = tokens.get();
		if (!t) break;

	}

	return 0;
}