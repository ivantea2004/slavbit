#include <iostream>
#include <slavbit/lexer/token_stream.hpp>

int main()
{
	using namespace slavbit;

	std::string code = R"(
	1 + 2 + 3 ; : L m ([[{}
)";
	
	lexer::token_stream tokens({code});

	while (true)
	{
		auto t = tokens.get();
		if (!t) break;

	}

	return 0;
}