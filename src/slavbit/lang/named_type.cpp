#include <slavbit/lang/named_type.hpp>

namespace slavbit::lang
{

	bool named_type::operator==(const type_base& other) const
	{
		if (auto nt = dynamic_cast<const named_type*>(&other); nt)
		{
			return id == nt->id;
		}
		return false;
	}

	std::string named_type::to_string() const
	{
		return std::string(id->name());
	}

}