#pragma once
#include <slavbit/lang/type_base.hpp>
#include <vector>
#include <memory>

namespace slavbit::lang
{

	class function_type : public type_base
	{
	public:
		std::vector<std::shared_ptr<type_base>> args;
		std::shared_ptr<type_base> return_type;

		bool operator==(const type_base& other) const override
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

		std::string to_string() const override
		{
			return "():" + return_type->to_string();
		}

	};

}