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

		bool operator==(const type_base& other) const override;
		std::string to_string() const override;

	};

}