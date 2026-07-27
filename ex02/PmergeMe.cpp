/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:25:23 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/28 01:29:42 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::getJacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

void	PmergeMe::checkValid(const std::string &numbers)
{
	for (size_t i = 0; i < numbers.length(); i++)
		if (numbers[i] != ' ' && !isdigit(numbers[i]))
			throw std::runtime_error("invalid input");
}

long long getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

std::vector<int> &PmergeMe::getVector()
{
	return this->_vector;
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

void PmergeMe::printAfter()
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}


std::vector <int> PmergeMe::fordJohnsonVector(const std::vector <int> &input)
{
	if (input.size() <= 1)
	return input;

	int straggler = -1;
	bool hasStraggler = false;
	if (input.size() % 2 != 0) {
		hasStraggler = true;
		straggler = input[input.size() - 1];
	}

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;
	std::vector<int> losers;

	createVectorPairs(input, pairs, winners, losers);

	std::vector<int> sortedWinners = fordJohnsonVector(winners);

	std::vector<int> alignedLosers = alignVectorLosers(sortedWinners, pairs);

	return insertVectorElements(sortedWinners, alignedLosers, straggler, hasStraggler);
}

void PmergeMe::createVectorPairs(const std::vector<int> &input,
	std::vector<std::pair<int, int> > &pairs,
	std::vector<int> &winners,
	std::vector<int> &losers)
{
	for (size_t i = 0; i < input.size() - 1; i += 2)
	{
		if (input[i] > input[i + 1])
		{
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
			winners.push_back(input[i]);
			losers.push_back(input[i + 1]);
		}
		else
		{
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
			winners.push_back(input[i + 1]);
			losers.push_back(input[i]);
		}
	}
}

std::vector<int> PmergeMe::alignVectorLosers(const std::vector<int> &sortedWinners, const std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> aligned;
	for (size_t i = 0; i < sortedWinners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedWinners[i])
			{
				aligned.push_back(pairs[j].second);
				break;
			}
		}
	}
	return aligned;
}

std::vector<int> PmergeMe::insertVectorElements(const std::vector<int> &sortedWinners,
	const std::vector<int> &alignedLosers,
	int straggler, bool hasStraggler)
{
	std::vector<int> mainChain;
	if (alignedLosers.empty())
		return sortedWinners;

	mainChain.push_back(alignedLosers[0]);
	for (size_t i = 0; i < sortedWinners.size(); i++)
		mainChain.push_back(sortedWinners[i]);

	std::vector<int> pendingElements;
	for (size_t i = 1; i < alignedLosers.size(); i++)
		pendingElements.push_back(alignedLosers[i]);
	if (hasStraggler)
		pendingElements.push_back(straggler);

	int jacobIndex = 3;
	size_t lastPos = 0;

	while (lastPos < pendingElements.size())
	{
		size_t currentPos = getJacobsthal(jacobIndex) - 1;

		if (currentPos > pendingElements.size())
			currentPos = pendingElements.size();

		for (size_t i = currentPos; i > lastPos; i--)
			mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), pendingElements[i - 1]), pendingElements[i - 1]);

		lastPos = currentPos;
		jacobIndex++;
	}
	return mainChain;
}

void PmergeMe::sortVector()
{
	// std::vector< std::pair <int, int> > original;
	_vector = fordJohnsonVector(_vector);

}

// void PmergeMe::sortDeque()
// {
// 	// std::deque< std::pair <int, int> > original;
// 	_deque = fordJohnsonDeque(_deque);
// }


