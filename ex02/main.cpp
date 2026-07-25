/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 19:25:26 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/25 21:12:59 by snazzal          ###   ########.fr       */
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
		pmergeMe.sortVector();
		pmergeMe.sortDeque();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
