#include <slavbit/lexer/bracket.hpp>
#include <span>
#include <algorithm>

namespace slavbit::lexer
{

	static std::span<std::pair<bracket, std::string_view>> bracket_mapping()
	{
		using enum bracket;
		static std::pair<bracket, std::string_view> map[] = {
			{open_paren, "("},
			{close_paren, ")"},
			{open_square, "["},
			{close_square, "]"},
			{open_curve, "{"},
			{close_curve, "}"}
		};
		return map;
	}

	bool from_string(std::string_view s, bracket&b)
	{
		auto map = bracket_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.second == s;
		});
		if (it == map.end())
		{
			return false;
		}
		else
		{
			b = it->first;
			return true;
		}
	}
	std::string to_string(bracket b)
	{
		auto map = bracket_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.first == b;
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