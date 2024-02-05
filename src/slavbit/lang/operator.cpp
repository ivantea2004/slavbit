#include <slavbit/lang/operator.hpp>

namespace slavbit::lang
{

	bool from_string(std::string_view s, binary_arithmetic_operator& op, bool with_assign)
	{
		using enum binary_arithmetic_operator;
		if (with_assign)
		{
			if (s.size() <= 1)
				return false;
			if (s.back() != '=')
				return false;
			binary_arithmetic_operator out;
			bool res = from_string(std::string_view{ s.begin(), s.end() - 1 }, out, false);
			if (!res)
				return false;
			if (out == id)
				return false;
			op = out;
			return true;
		}
		else
		{
			if (s == "=")
			{
				op = id;
				return true;
			}
			if (s == "+")
			{
				op = plus;
				return true;
			}
			if (s == "*")
			{
				op = mult;
				return true;
			}
			return false;
		}
	}
	bool from_string(std::string_view s, unary_arithmetic_operator& op)
	{
		using enum unary_arithmetic_operator;
		if (s == "+")
		{
			op = plus;
			return true;
		}
		return false;
	}

}