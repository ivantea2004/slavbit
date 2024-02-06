#include <slavbit/lang/global_scope.hpp>
#include <slavbit/lang/type_identifier.hpp>

namespace slavbit::lang
{

	global_scope::global_scope(core::location declaration_location) : 
		scope(
			"",
			false,
			nullptr,
			nullptr,
			declaration_location
		)
	{
		declare_buildins();
	}

	void global_scope::declare_buildins()
	{
		const lang::identifier_base* other;
		declare<lang::type_identifier>(other, "int", false, nullptr, {});
	}

}