/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:22:06 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/25 16:12:42 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

bool isOperator(const std::string &token)
{
	return (token == "+"
			|| token == "-"
			|| token == "/"
			|| token == "*");
}

int RPN::calculate(int first, int second, const std::string &operation)
{
	char op = operation[0];
	int res = 0;
	switch (op)
	{
	case '+':
		res = first + second;
		break;

	case '-':
		res = first - second;
		break;

	case '/':
		res = first / second;
		break;

	case '*':
		res = first * second;
		break;
	}
	return res;
}


void RPN::evaluate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while (ss >> token)
	{
		int res;


		if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("invalid expression");
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			if (num2 == 0 && token == "/")
				throw std::runtime_error("division by zero is not allowed");
			_stack.push(calculate(num1, num2, token));
		}
		else
		{
			if (token.length() > 1)
				throw std::runtime_error("invalid expression");
			std::stringstream convert;
			convert << token;
			convert >> res;
			_stack.push(res);
		}
	}

	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl;
	}
	else
		throw std::runtime_error("invalid expression");

}
