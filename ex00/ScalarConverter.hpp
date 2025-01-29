/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:26:17 by vvaalant          #+#    #+#             */
/*   Updated: 2025/01/29 14:32:01 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define DEFAULT "\033[0m"

class ScalarConverter
{
	private:
		ScalarConverter() {};
        ScalarConverter(ScalarConverter const &) = delete;
        ScalarConverter &operator=(ScalarConverter const &) = delete;
		~ScalarConverter() = default;
	public:
		static void convert(std::string const & str);
};

#endif
