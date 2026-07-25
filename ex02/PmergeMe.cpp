/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:25:23 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/25 21:34:22 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void	checkValid(const std::string &numbers)
{
	for (size_t i = 0; i < numbers.length(); i++)
		if (numbers[i] != ' ' && !isdigit(numbers[i]))
			throw std::runtime_error("invalid input");
}

void PmergeMe::parse(const std::string &numbers)
{
	checkValid(numbers);

	std::stringstream ss(numbers);
	long number;
	std::cout << "Before: ";
	while (ss >> number)
	{
		_vector.push_back(number);
		_deque.push_back(number);
		if (number > INT_MAX)
			throw std::runtime_error("Overflow");
		std::cout << number << " ";
	}
	std::cout << std::endl;
}

std::vector <int> PmergeMe::fordJohnsonVector(std::vector <int> &input)
{
	if (input.size() < 1)
		return input;

	std::vector <std::pair <int, int>> pairs;
	int straggler;
	bool hasStraggler;

}


void PmergeMe::sortVector()
{
	// std::vector< std::pair <int, int> > original;
	_vector = fordJohnsonVector(_vector);

}

void PmergeMe::sortDeque()
{
	// std::deque< std::pair <int, int> > original;
	_deque = fordJohnsonDeque(_deque);
}


