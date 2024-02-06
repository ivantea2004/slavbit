#pragma once
#include <slavbit/lang/type_base.hpp>
#include <slavbit/lang/type_identifier.hpp>

namespace slavbit::lang
{

	class named_type : public type_base
	{
	public:
		const type_identifier* id;
	
		bool operator==(const type_base& other) const override;
		std::string to_string() const override;

	};

}