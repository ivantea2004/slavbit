#pragma once
#include <slavbit/lang/identifier_base.hpp>

namespace slavbit::lang
{

	class scope_identifier : public identifier_base
	{
	public:
		using identifier_base::identifier_base;
		
		virtual const identifier_base* lookup(std::string_view) const = 0;
		
	};

}