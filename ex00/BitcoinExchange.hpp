/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:34:52 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/31 13:43:13 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <climits>

class BitcoinExchange
{
private:
	std::map <std::string, double>	_database;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange operator =(const BitcoinExchange &other);
	~BitcoinExchange();
	void parseInput(int argc, char **argv);
	std::pair <std::string, double> parseLine(const std::string &line, char seperator);
	void checkInput(std::pair <std::string, double> input);
};


#endif
