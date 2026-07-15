/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:34:52 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/15 13:22:55 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <climits>

//TODO: canonical forms

class BitcoinExchange
{
private:
	std::map <std::string, double>	_database;
	// std::map <std::string, double>	_input;
public:
	BitcoinExchange();
	~BitcoinExchange();
	void parseInput(int argc, char **argv);
	// void parseDatabaseLine(const std::string &line);
	std::pair <std::string, double> parseLine(const std::string &line, char seperator);
	void checkInput(std::pair <std::string, double> input);
};


#endif
