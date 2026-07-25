/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:21:34 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/25 15:53:04 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
// #include <string>

class RPN
{
private:
	std::stack <int> _stack;
public:
	RPN();
	~RPN();
	void evaluate(const std::string &expression);
	int calculate(int first, int second, const std::string &operation);
};

bool isOperator(const std::string &token);

#endif
