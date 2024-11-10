/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:26:22 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 02:28:49 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	{
		std::cout << CYAN << "----------------------------------------" << std::endl;
		std::cout << "Test 0: " << "empty string and char literals" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		ScalarConverter::convert("");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("a");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("b");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("c");
	}
	{
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 1: " << "'0' and '42'" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		ScalarConverter::convert("0");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42.0f");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42.0");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42.42");
	}
	{ // over and underflows
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 2: " << "over and underflows" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		ScalarConverter::convert("2147483647");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("2147483648");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("-2147483648");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("-2147483649");
	}
	{ // non displayable
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 3: " << "non displayable" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		ScalarConverter::convert("127");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("128");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("33");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("32");
	}
	{ // impossible
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 4: " << "impossible" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		ScalarConverter::convert("42.42.42");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42.42.42f");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert(".42.0");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert(".42.0f");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42a");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		ScalarConverter::convert("42.0a");
	}
	{ // special cases
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 5: " << "special cases" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;

		std::cout << "converting 'nan'" << std::endl;
		ScalarConverter::convert("nan");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting 'inf'" << std::endl;
		ScalarConverter::convert("inf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting '-inf'" << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting 'nanf'" << std::endl;
		ScalarConverter::convert("nanf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting " << "'inff'" << std::endl;
		ScalarConverter::convert("inff");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting " << "'-inff'" << std::endl;
		ScalarConverter::convert("-inff");
	}
}
