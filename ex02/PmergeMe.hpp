/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:53:21 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/25 21:15:09 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>

class PmergeMe
{
private:
	std::vector <int> _vector;
	std::deque <int> _deque;

	std::vector <int> fordJohnsonVector(std::vector <int> &input);
	std::deque <int> fordJohnsonDeque(std::deque <int> &input);
public:
	PmergeMe();
	~PmergeMe();

	std::vector<int> &getVector();
	std::deque<int> &getDeque();

	void parse(const std::string &numbers);
	void sortVector();
	void sortDeque();
};

void	checkValid(const std::string &numbers);
