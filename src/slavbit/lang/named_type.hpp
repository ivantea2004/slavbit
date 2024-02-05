#pragma once
#include <slavbit/lang/type_base.hpp>
#include <slavbit/lang/type_identifier.hpp>

namespace slavbit::lang
{

	class named_type : public type_base
	{
	public:
		const type_identifier* id;
	
		bool operator==(const type_base& other) const override
		{
			if (auto nt = dynamic_cast<const named_type*>(&other); nt)
			{
				return id == nt->id;
			}
			return false;
		}
	
		std::string to_string() const override
		{
			return std::string(id->name());
		}

	};

}