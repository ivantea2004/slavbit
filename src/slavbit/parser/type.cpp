#include <slavbit/parser/type.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/core/compilation_error.hpp>

namespace slavbit::parser
{

	std::shared_ptr<lang::type_base> parse_type(
		lexer::token_stream& tokens,
		const lang::scope& scope,
		core::diagnostic_stream&ds
	)
	{
		if (tokens.end())
			throw core::unexpected_end_error(tokens.end_location());
		lexer::token name = *tokens.get();
		if (name.is_identifier())
		{
			auto*id = scope.lookup(name.as_identifier());
			if (id)
			{
				if (auto* tid = dynamic_cast<const lang::type_identifier*>(id); tid)
				{
					auto named = std::make_shared<lang::named_type>();
					named->id = tid;
					return named;
				}
				ds.push(core::syntax_error(name, "'" + std::string(id->name()) + "' is not a type name"));
				return nullptr;
			}
			ds.push(core::syntax_error(name, "'" + std::string(name.as_identifier()) + "' is not a type name"));
			return nullptr;
		}
		throw core::expected_identifier_error(name, "type");
	}

}