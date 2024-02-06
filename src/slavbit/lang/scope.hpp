#pragma once
#include <vector>
#include <slavbit/lang/scope_identifier.hpp>

namespace slavbit::lang
{

	class scope : public scope_identifier
	{
	public:

		scope(
			std::string name,
			bool hidden,
			const scope*outer,
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
		
		const identifier_base* lookup(std::string_view name) const override
		{
			auto in_curr = do_lookup(name);
			if (in_curr)
				return in_curr;
			if (get_scope())
				return get_scope()->lookup(name);
			return nullptr;
		}

		template<typename Id, typename...Args>
		Id* declare(
			const identifier_base*&conflicting,
			std::string name, bool hidden,
			std::shared_ptr<type_base> type,
			core::location declration_location,
			Args&&...args
		)
		{
			auto id = do_lookup(name);
			if (id)
			{
				if (Id * tid = dynamic_cast<Id*>(id); tid)
				{
					if (id->type() && type && *id->type() == *type || !id->type() && !type) // if types are the same
					{
						return tid;
					}
					else
					{
						conflicting = id;
						return nullptr;
					}
				}
				else
				{
					conflicting = id;
					return nullptr;
				}
			}
			else
			{
				auto new_id = std::make_unique<Id>(name, hidden, this, type, declration_location, std::forward<Args>(args)...);
				auto ptr = new_id.get();
				identifiers_.push_back(std::move(new_id));
				return ptr;
			}
		}

	private:

		identifier_base* do_lookup(std::string_view name) const
		{
			for (auto& i : identifiers_)
				if (!i->is_hidden() && i->name() == name)
					return i.get();
			return nullptr;
		}
		std::vector<std::unique_ptr<identifier_base>> identifiers_;
	};

}