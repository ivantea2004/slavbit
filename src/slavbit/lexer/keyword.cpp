#include <slavbit/lexer/keyword.hpp>
#include <span>
#include <algorithm>

namespace slavbit::lexer
{

	static std::span<std::pair<keyword, std::string_view>> keyword_mapping()
	{
		using enum keyword;
		static std::pair<keyword, std::string_view> map[] = {
			{let, "let"},
			{function, "function"}
		};
		return map;
	}

	bool from_string(std::string_view s, keyword& k)
	{
		auto map = keyword_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.second == s;
		});
		if (it == map.end())
		{
			return false;
		}
		else
		{
			k = it->first;
			return true;
		}
	}
	std::string to_string(keyword k)
	{
		auto map = keyword_mapping();
		auto it = std::find_if(map.begin(), map.end(), [&](auto i) {
			return i.first == k;
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