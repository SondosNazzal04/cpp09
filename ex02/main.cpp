/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:25:26 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/29 16:03:28 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeMe;
		if (argc == 2)
			pmergeMe.parse(argv[1]);
		else
		{
			for (int i = 1; i < argc; i++)
				pmergeMe.addElement(argv[i]);
			std::cout << "Before: ";
			for (size_t i = 0; i < pmergeMe.getDeque().size(); i++)
				std::cout << pmergeMe.getDeque()[i] << " ";
			std::cout << std::endl;
		}

		long long startVector = getTime();
		pmergeMe.sortVector();
		long long endVector = getTime();

		pmergeMe.printAfter();

		std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector : " << static_cast<double>(endVector - startVector) << " us\n";

		long long startDeque = getTime();
		pmergeMe.sortDeque();
		long long endDeque = getTime();

		std::cout << "Time to process a range of " << pmergeMe.getDeque().size() << " elements with std::deque : " << static_cast<double>(endDeque - startDeque) << " us\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
