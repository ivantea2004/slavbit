#include <slavbit/lexer/control_sign.hpp>
#include <span>
#include <algorithm>

namespace slavbit::lexer
{

	static std::span<std::pair<control_sign, std::string_view>> control_sign_mapping()
	{
		using enum control_sign;
		static std::pair<control_sign, std::string_view> map[] = {
			{comma, ","},
			{colon, ":"},
			{semicolon, ";"}
		};
		return map;
	}

	bool from_string(std::string_view s, control_sign& c)
	{
		auto map = control_sign_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.second == s;
		});
		if (it == map.end())
		{
			return false;
		}
		else
		{
			c = it->first;
			return true;
		}
	}
	std::string to_string(control_sign c)
	{
		auto map = control_sign_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.first == c;
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