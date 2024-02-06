#include <slavbit/core/diagnostic_stream.hpp>
#include <iostream>

namespace slavbit::core
{

	void diagnostic_stream::write(const diagnostic_message& messge)
	{
		std::cout << messge.text();
	}

}