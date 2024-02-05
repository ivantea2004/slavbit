#pragma once
#include <string>

namespace slavbit::core
{

	struct source_code
	{
		std::string_view text;
	};

	struct location
	{
		location() = default;
		location(location begin, location end) :
			location(begin.code_, begin.begin_, end.begin_)
		{}
		location(source_code code, size_t offset) :
			code_(code),
			begin_(offset >= code.text.size() ? code.text.size() - 1 : offset),
			end_(begin_ + 1)
		{}
		location(source_code code, size_t begin, size_t end) :
			code_(code),
			begin_(begin),
			end_(end)
		{}

		std::string render(bool highlight) const
		{
			return std::string(code_.text.begin() + begin_, code_.text.begin() + end_) + "\n";
		}

		source_code code_;
		size_t begin_, end_;
	};

}