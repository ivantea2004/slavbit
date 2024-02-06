#include <slavbit/lang/scope.hpp>

namespace slavbit::lang
{

	scope::scope(
		std::string name,
		bool hidden,
		const scope* outer,
		std::shared_ptr<type_base> type,
		core::location declaration_location
	) :
		scope_identifier(
			name,
			hidden,
			outer,
			type,
			declaration_location
		)
	{}

	const identifier_base* scope::lookup(std::string_view name) const
	{
		auto in_curr = do_lookup(name);
		if (in_curr)
			return in_curr;
		if (get_scope())
			return get_scope()->lookup(name);
		return nullptr;
	}

	identifier_base* scope::do_lookup(std::string_view name) const
	{
		for (auto& i : identifiers_)
			if (!i->is_hidden() && i->name() == name)
				return i.get();
		return nullptr;
	}

}