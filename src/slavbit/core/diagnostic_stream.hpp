#pragma once
#include <slavbit/core/compilation_error.hpp>
#include <iostream>

namespace slavbit::core
{

	class diagnostic_stream
	{
	public:

		void push(const compilation_error& e)
		{
			std::cout << e.render_diagnostics();
		}

	private:

	};

}