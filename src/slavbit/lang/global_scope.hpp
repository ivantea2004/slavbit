#pragma once
#include <slavbit/lang/scope.hpp>

namespace slavbit::lang
{

	class global_scope : public scope
	{
	public:

		global_scope(core::location declaration_location);

	private:

		void declare_buildins();

	};

}