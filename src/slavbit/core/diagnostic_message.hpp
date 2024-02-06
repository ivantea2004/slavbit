#pragma once
#include <string>

namespace slavbit::core
{

	class diagnostic_message
	{
	public:
		virtual std::string text() const = 0;
		virtual ~diagnostic_message() = default;
	};

}