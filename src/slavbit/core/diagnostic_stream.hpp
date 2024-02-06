#pragma once
#include <slavbit/core/diagnostic_message.hpp>

namespace slavbit::core
{

	class diagnostic_stream
	{
	public:

		void write(const diagnostic_message& msg);

	};

}