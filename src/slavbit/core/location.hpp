#pragma once
#include <slavbit/core/source_code.hpp>
#include <slavbit/core/line_iterator.hpp>

namespace slavbit::core
{

	struct location
	{
		location() = default;
		location(location begin, location end);
		location(source_code code, size_t offset);
		location(source_code code, size_t begin, size_t end);

		line_iterator lines_begin() const;
		line_iterator lines_end() const;
		std::string render(bool highlight) const;
	private:
		source_code code_;
		size_t begin_, end_;
	};

}