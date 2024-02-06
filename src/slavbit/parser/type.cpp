#include <slavbit/parser/type.hpp>
#include <slavbit/lang/named_type.hpp>
#include <slavbit/core/unexpected_end_error.hpp>
#include <slavbit/parser/unexpected_token_error.hpp>
#include <slavbit/parser/undeclared_error.hpp>
#include <slavbit/parser/unexpected_identifier_error.hpp>

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
				ds.write(parser::unexpected_identifier_error(name, id, expectable::type_name));
				return nullptr;
			}
			ds.write(parser::undeclared_error(name, std::string(name.as_identifier())));
			return nullptr;
		}
		throw parser::unexpected_token_error(name, expectable::type_name);
	}

}