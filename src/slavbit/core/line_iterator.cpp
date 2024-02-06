#include <slavbit/core/line_iterator.hpp>

namespace slavbit::core
{

	line_iterator::line_iterator(std::string_view text) :
		line_iterator(text, text.size(), text.size(), 0)
	{}

	line_iterator::line_iterator(std::string_view text, size_t begin, size_t end, size_t line_number) :
		text_(text),
		begin_(begin),
		end_(end),
		line_number_(line_number_)
	{}
	line_iterator::line_iterator(std::string_view text, size_t offset) :
		text_(text),
		begin_(find_line_begin(offset)),
		end_(find_line_end(offset)),
		line_number_(calc_line_number(offset))
	{}

	size_t line_iterator::line_number() const
	{
		return line_number_;
	}
	size_t line_iterator::begin() const
	{
		return begin_;
	}
	size_t line_iterator::end() const
	{
		return end_;
	}
	std::string_view line_iterator::operator*() const
	{
		if (text_[end_ - 1] == '\n')
			return { text_.begin() + begin_, text_.begin() + end_ - 1 };
		else
			return { text_.begin() + begin_, text_.begin() + end_ };
	}
	line_iterator& line_iterator::operator++()
	{
		begin_ = end_;
		end_ = find_line_end(end_);
		line_number_++;
		return *this;
	}
	bool line_iterator::operator==(const line_iterator& other) const
	{
		return begin_ == other.begin_;
	}

	size_t line_iterator::find_line_begin(size_t offset) const
	{
		if (offset == 0)
			return 0;
		if (offset == text_.size())
			return offset;
		if (text_[offset] == '\n')
			offset--;
		while (offset > 0 && text_[offset] != '\n')
			offset--;
		if (text_[offset] == '\n')
			return offset + 1;
		return 0;
	}
	size_t line_iterator::find_line_end(size_t offset) const
	{
		while (offset < text_.size() && text_[offset] != '\n')
			offset++;
		return offset != text_.size() ? offset + 1 : offset;
	}
	size_t line_iterator::calc_line_number(size_t offset) const
	{
		size_t lines = 0;
		for (size_t i = 0; i < offset; i++)
			if (text_[i] == '\n')
				lines++;
		return lines;
	}

}