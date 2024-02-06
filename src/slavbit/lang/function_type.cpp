#include <slavbit/lang/function_type.hpp>

namespace slavbit::lang
{

	bool function_type::operator==(const type_base& other) const
	{
		if (auto* ft = dynamic_cast<const function_type*>(&other); ft)
		{
			if (*return_type != *ft->return_type)
				return false;
			if (args.size() != ft->args.size())
				return false;
			for (size_t i = 0; i < args.size(); i++)
				if (*args[i] != *ft->args[i])
					return false;
			return true;
		}
		return false;
	}

	std::string function_type::to_string() const
	{
		std::string out;
		if (args.size() > 0)
		{
			out += ":" + args[0]->to_string();
			for (size_t i = 1; i < args.size(); i++)
				out += ",:" + args[i]->to_string();
		}
		return "(" + out + "):" + return_type->to_string();
	}

}