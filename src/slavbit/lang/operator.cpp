#include <slavbit/lang/operator.hpp>
#include <span>
#include <algorithm>

namespace slavbit::lang
{


	static std::span<std::pair<binary_arithmetic_operator, std::string_view>> binary_arithmetic_mapping()
	{
		using enum binary_arithmetic_operator;
		static std::pair<binary_arithmetic_operator, std::string_view> map[] = {
			{id, "="},
			{plus, "+"},
			{mult, "*"}
		};
		return map;
	}

	static std::span<std::pair<unary_arithmetic_operator, std::string_view>> unary_arithmetic_mapping()
	{
		using enum unary_arithmetic_operator;
		static std::pair<unary_arithmetic_operator, std::string_view> map[] = {
			{plus, "+"}
		};
		return map;
	}

	bool from_string(std::string_view s, binary_arithmetic_operator&o, bool with_assign)
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
			o = out;
			return true;
		}
		else
		{
			auto map = binary_arithmetic_mapping();
			auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
				return i.second == s;
			});
			if (it == map.end())
			{
				return false;
			}
			else
			{
				o = it->first;
				return true;
			}
		}
	}
	std::string to_string(binary_arithmetic_operator o)
	{
		auto map = binary_arithmetic_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.first == o;
		});
		if (it == map.end())
		{
			return "";
		}
		else
		{
			return std::string(it->second);
		}
	}

	bool from_string(std::string_view s, unary_arithmetic_operator&o)
	{
		auto map = unary_arithmetic_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.second == s;
		});
		if (it == map.end())
		{
			return false;
		}
		else
		{
			o = it->first;
			return true;
		}
	}
	std::string to_string(unary_arithmetic_operator o)
	{
		auto map = unary_arithmetic_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.first == o;
		});
		if (it == map.end())
		{
			return "";
		}
		else
		{
			return std::string(it->second);
		}
	}

}