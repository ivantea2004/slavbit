#pragma once
#include<stdexcept>
#include <slavbit/core/location.hpp>
#include <slavbit/core/diagnostic_message.hpp>

namespace slavbit::core
{

	class code_error : public diagnostic_message, public std::runtime_error
	{
	public:
		code_error(core::location location);

		std::string text() const;
		virtual std::string error_text() const = 0;
		virtual std::string error_body() const;
	protected:
		core::location error_location;
	};

}