/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:26:19 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 01:23:42 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}

void	ScalarConverter::convert(std::string const & str)
{
	int dot = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dot++;
		if (i + 1 == str.length() && dot == 1)
			break;
		if (dot > 1)
		{
			std::cout << "impossible conversion!" << std::endl;
			return;
		}
	}
	std::cout << "char: ";
	try
	{
		int i = std::stoi(str);
		if (i < 32 || i > 126)
			throw std::exception();
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	try
	{
		int i = std::stoi(str);
		std::cout << i << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		float f = std::stof(str);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	try
	{
		double d = std::stod(str);
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "impossible" << std::endl;
	}
}
