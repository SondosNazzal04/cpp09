/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:25:26 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/28 01:30:15 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of argumnets" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmergeMe;
		pmergeMe.parse(argv[1]);

		long long startVector = getTime();
		pmergeMe.sortVector();
		long long endVector = getTime();

		pmergeMe.printAfter();

		std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector : " << static_cast<double>(endVector - startVector) << " us\n";
		// pmergeMe.sortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
