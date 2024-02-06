#include <slavbit/core/location.hpp>

namespace slavbit::core
{

	location::location(location begin, location end) :
		location(begin.code_, begin.begin_, end.begin_)
	{}
	location::location(source_code code, size_t offset) :
		code_(code),
		begin_(offset >= code_.text.size() ? code_.text.size() : offset),
		end_(offset >= code.text.size() ? code_.text.size() : offset)
	{}
	location::location(source_code code, size_t begin, size_t end) :
		code_(code),
		begin_(begin),
		end_(end)
	{}

	line_iterator location::lines_begin() const
	{
		return line_iterator(code_.text, begin_);
	}

	line_iterator location::lines_end() const
	{
		line_iterator line(code_.text, end_);
		if (end_ == line.begin())
			return line;
		else
			return ++line;
	}

	std::string location::render(bool highlight) const
	{
		std::string out;

		std::vector<std::string> line_numbers;

		for (auto i = lines_begin(); i != lines_end(); ++i)
			line_numbers.push_back(std::to_string(i.line_number() + 1));

		size_t max_line_number_len = 0;

		for (auto& i : line_numbers)
			max_line_number_len = std::max(max_line_number_len, i.length());

		for (auto& i : line_numbers)
			i = std::string(max_line_number_len - i.length(), ' ') + i;

		size_t ln = 0;
		for (auto i = lines_begin(); i != lines_end(); ++i, ln++)
		{
			std::string line_highlight;
			bool hightlighted_any = false;
			if (highlight) {
				for (size_t j = i.begin(); j < i.end(); j++)
					if (j < begin_ || j >= end_ || std::isspace(code_.text[j]))
					{
						line_highlight += ' ';
					}
					else
					{
						line_highlight += '^';
						hightlighted_any = true;
					}
			}
			out += line_numbers[ln] + ":" + std::string(*i) + "\n";
			if (hightlighted_any) out += std::string(max_line_number_len, ' ') + "|" + line_highlight + "\n";
			
		}
		return out;
	}

}