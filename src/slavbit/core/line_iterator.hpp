#pragma once
#include <string>

namespace slavbit::core
{

	class line_iterator
	{
	public:

		line_iterator(std::string_view text);
		line_iterator(std::string_view text, size_t begin, size_t end, size_t line_number);
		line_iterator(std::string_view text, size_t offset);

		size_t line_number() const;
		size_t begin() const;
		size_t end() const;
		std::string_view operator*() const;
		line_iterator& operator++();
		bool operator==(const line_iterator& other) const;

	private:

		size_t find_line_begin(size_t offset) const;
		size_t find_line_end(size_t offset) const;
		size_t calc_line_number(size_t offset) const;

		std::string_view text_;
		size_t begin_, end_; // begin and end of line
		size_t line_number_;
	};

}