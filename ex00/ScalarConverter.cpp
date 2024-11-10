/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:26:19 by vvaalant          #+#    #+#             */
/*   Updated: 2024/11/10 02:30:05 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isValid(std::string const & str)
{
	if (str.empty())
		return false;

	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" ||
			str == "-inf" || str == "-inff" || str == "inf" || str == "inff")
		return true;

	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;

	bool	hasDecimal = false;
	bool	hasFloat = false;
	bool	hasSign = (str[0] == '-' || str[0] == '+');

	for (size_t i = hasSign ? 1 : 0; i < str.length(); i++)
	{
		char c = str[i];
		if (std::isdigit(c))
			continue;
		if (c == '.' && !hasDecimal)
		{
			hasDecimal = true;
			continue;
		}
		if (c == 'f' && !hasFloat && i == str.length() - 1)
		{
			hasFloat = true;
			continue;
		}
		return false;
	}
	return true;
}

void	ScalarConverter::convert(std::string const & str)
{
	if (isValid(str) == false)
	{
		std::cout << "impossible conversion!" << std::endl;
		return;
	}

	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
		return;
	}

	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
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
