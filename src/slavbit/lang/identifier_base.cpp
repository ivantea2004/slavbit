#include <slavbit/lang/identifier_base.hpp>
#include <slavbit/lang/scope.hpp>

namespace slavbit::lang
{

	identifier_base::identifier_base(
		std::string name,
		bool hidden,
		const scope* scope,
		std::shared_ptr<type_base>type,
		core::location declaration_location
	) :
		name_(name),
		hidden_(hidden),
		scope_(scope),
		type_(type),
		declaration_location_(declaration_location)
	{}

	std::string_view identifier_base::name() const
	{
		return name_;
	}
	bool identifier_base::is_hidden() const
	{
		return hidden_;
	}
	const scope* identifier_base::get_scope() const
	{
		return scope_;
	}
	std::shared_ptr<type_base> identifier_base::type() const
	{
		return type_;
	}
	core::location identifier_base::declaration_location() const
	{
		return declaration_location_;
	}

	std::string identifier_base::full_name() const
	{
		if (scope_)
			return scope_->full_name() + "::" + std::string(name());
		else
			return "";
	}

}