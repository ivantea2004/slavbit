#pragma once
#include <string>

namespace slavbit::lang
{

	enum class binary_arithmetic_operator
	{
		id,
		plus,
		mult
	};

	enum class unary_arithmetic_operator
	{
		plus
	};

	bool from_string(std::string_view, binary_arithmetic_operator&, bool with_assign);
	std::string to_string(binary_arithmetic_operator);

	bool from_string(std::string_view, unary_arithmetic_operator&);
	std::string to_string(unary_arithmetic_operator);

}