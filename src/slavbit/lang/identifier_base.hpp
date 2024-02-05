#pragma once
#include <string>
#include <memory>
#include <slavbit/lang/type_base.hpp>

namespace slavbit::lang
{

	class scope;

	class identifier_base
	{
	public:
		identifier_base(std::string name, bool hidden, const scope*scope, std::shared_ptr<type_base>type) :
			name_(name),
			hidden_(hidden),
			scope_(scope),
			type_(type)
		{}
		virtual ~identifier_base() = default;

		std::string_view name() const
		{
			return name_;
		}
		bool is_hidden() const
		{
			return hidden_;
		}
		const scope* get_scope() const
		{
			return scope_;
		}
		std::shared_ptr<type_base> type() const
		{
			return type_;
		}
	private:
		std::string name_;
		bool hidden_;
		const scope* scope_;
		std::shared_ptr<type_base> type_;
	};

}