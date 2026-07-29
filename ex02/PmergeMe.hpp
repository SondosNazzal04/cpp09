/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:53:21 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/29 16:05:34 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <algorithm> // For std::lower_bound
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector <int> _vector;
	std::deque <int> _deque;

	//helper functions
	int		getJacobsthal(int n);
	void	checkValid(const std::string &numbers);

	//create pairs
	void createVectorPairs(const std::vector<int> &input,
		std::vector<std::pair<int, int> > &pairs,
		std::vector<int> &winners,
		std::vector<int> &losers);

	void createDequePairs(const std::deque<int> &input,
		std::deque<std::pair<int, int> > &pairs,
		std::deque<int> &winners,
		std::deque<int> &losers);

	//align losers
	std::vector<int> alignVectorLosers(const std::vector<int> &sortedWinners,
		const std::vector<std::pair<int, int> > &pairs);

	std::deque<int> alignDequeLosers(const std::deque<int> &sortedWinners,
		const std::deque<std::pair<int, int> > &pairs);

	//insert jacobstal
	std::vector<int> insertVectorElements(const std::vector<int> &sortedWinners,
		const std::vector<int> &alignedLosers,
		int straggler, bool hasStraggler);

	std::deque<int> insertDequeElements(const std::deque<int> &sortedWinners,
		const std::deque<int> &alignedLosers,
		int straggler, bool hasStraggler);

	// apply fordjohnson
	std::vector <int> fordJohnsonVector(const std::vector <int> &input);
	std::deque <int> fordJohnsonDeque(const std::deque <int> &input);
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe operator=(const PmergeMe &other);
	~PmergeMe();

	std::vector<int> &getVector();
	std::deque<int> &getDeque();

	void parse(const std::string &numbers);
	void addElement(char *argv);
	void printAfter();
	void sortVector();
	void sortDeque();
};

long long getTime();
