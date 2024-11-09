/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:26:22 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 01:25:44 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
	{
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 1: " << "'0' and '42'" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;
		ScalarConverter sc;

		sc.convert("0");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("42");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("42.0f");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("42.0");
	}
	{ // over and underflows
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 2: " << "over and underflows" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;
		ScalarConverter sc;

		sc.convert("2147483647");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("2147483648");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("-2147483648");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("-2147483649");
	}
	{ // non displayable
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 3: " << "non displayable" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;
		ScalarConverter sc;

		sc.convert("127");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("128");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("33");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("32");
	}
	{ // impossible
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 4: " << "impossible" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;
		ScalarConverter sc;

		sc.convert("42.42.42");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		sc.convert("42.42.42f");
	}
	{ // special cases
		std::cout << CYAN << "\n----------------------------------------" << std::endl;
		std::cout << "Test 5: " << "special cases" << std::endl;
		std::cout << "----------------------------------------" << DEFAULT << std::endl;
		ScalarConverter sc;

		std::cout << "converting 'nan'" << std::endl;
		sc.convert("nan");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting 'inf'" << std::endl;
		sc.convert("inf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting '-inf'" << std::endl;
		sc.convert("-inf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting 'nanf'" << std::endl;
		sc.convert("nanf");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting " << "'inff'" << std::endl;
		sc.convert("inff");
		std::cout << GREEN << "----------------" << DEFAULT << std::endl;
		std::cout << "converting " << "'-inff'" << std::endl;
		sc.convert("-inff");
	}
}
