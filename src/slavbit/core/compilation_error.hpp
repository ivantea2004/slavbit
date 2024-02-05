#pragma once
#include <stdexcept>
#include <slavbit/core/source_code.hpp>

namespace slavbit::core
{

	class compilation_error : public std::runtime_error
	{
	public:
		compilation_error(location loc, std::string message) :
			std::runtime_error("compilation error"),
			loc(loc),
			message(message)
		{}
		std::string render_diagnostics() const
		{
			return "error: " + message + "\n" + loc.render(true);
		}
		std::string message;
		location loc;
	};

	class unexpected_end_error : public compilation_error
	{
	public:
		unexpected_end_error(location loc) : compilation_error(loc, "unexpected end") {}
	};

	class lexical_error : public compilation_error
	{
	public:
		using compilation_error::compilation_error;
	};

	class syntax_error : public compilation_error
	{
	public:
		using compilation_error::compilation_error;
	};

	class unexpected_char_error : public lexical_error
	{
	public:
		unexpected_char_error(core::location loc) : lexical_error(loc, "unexpected char") {}
	};

	class expected_identifier_error : public  syntax_error
	{
	public:
		expected_identifier_error(location loc, std::string id_type) : syntax_error(loc, "expected " + id_type + " identifier") {}
	};

}