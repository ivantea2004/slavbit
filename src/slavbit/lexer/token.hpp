#pragma once
#include <string>
#include <slavbit/core/location.hpp>
#include <slavbit/lang/operator.hpp>
#include <slavbit/lexer/control_sign.hpp>
#include <optional>

namespace slavbit::lexer
{

	struct token
	{

		bool operator==(lang::binary_arithmetic_operator op) const
		{
			return bin_arithm_ == op;
		}
		bool operator==(lang::unary_arithmetic_operator op) const
		{
			return un_arithm_ == op;
		}
		bool operator==(control_sign s) const
		{
			return control_ == s;
		}
		bool operator==(bracket b) const
		{
			return bracket_ == b;
		}
		bool operator==(keyword k) const
		{
			return keyword_ == k;
		}

		bool is_control() const
		{
			return control_.has_value();
		}

		control_sign as_control() const
		{
			return control_.value();
		}

		bool is_bracket() const
		{
			return bracket_.has_value();
		}
		bracket as_bracket()
		{
			return bracket_.value();
		}

		bool is_binary_operator() const
		{
			return bin_arithm_.has_value();
		}
		lang::binary_arithmetic_operator as_binary_operator() const
		{
			return bin_arithm_.value();
		}

		bool is_identifier() const
		{
			return id_.has_value();
		}
		std::string_view as_identifier() const
		{
			return id_.value();
		}

		bool is_keyword() const
		{
			return keyword_.has_value();
		}
		keyword as_keyword() const
		{
			return keyword_.value();
		}

		operator core::location() const
		{
			return location_;
		}

	private:
		std::optional<lang::binary_arithmetic_operator> assign_;
		std::optional<lang::binary_arithmetic_operator> bin_arithm_;
		std::optional<lang::unary_arithmetic_operator> un_arithm_;
		std::optional<control_sign> control_;
		std::optional<bracket> bracket_;
		std::optional<keyword> keyword_;
		std::optional<std::string_view> id_;
		std::optional<std::string_view> number_;
		std::optional<std::string_view> str_;
		core::location location_;
		friend class token_stream;

	};

}