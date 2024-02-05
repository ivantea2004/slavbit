#pragma once
#include <string>

namespace slavbit::lang
{

	class type_base
	{
	public:
		virtual bool operator==(const type_base&) const = 0;
		virtual std::string to_string() const = 0;
		virtual ~type_base() = default;
	};

}