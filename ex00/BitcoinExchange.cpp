/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:34:55 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/15 11:10:25 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair <std::string, double>	BitcoinExchange::parseLine(const std::string &line)
{
	std::stringstream	ss;
	double				exchangeRate;
	size_t				seperatorPos = line.find(",");
	if (seperatorPos == std::string::npos)
	{
		seperatorPos = line.find("|");
		if (seperatorPos == std::string::npos)
			throw std::runtime_error("seperator not found\n");
	}
	std::string			date = line.substr(0, seperatorPos);
	std::string			exchangeRateStr = line.substr(seperatorPos);
	ss << exchangeRateStr;
	ss >> exchangeRate;
	return std::make_pair(date, exchangeRate);
}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	std::fstream	fs("data.csv");
	if (!fs.is_open())
		throw std::runtime_error("Error: Failed to open file!");

	std::getline(fs, line);

	while (std::getline(fs, line))
	{
		this->parseLine(line);
		this->_database.insert(parseLine(line));
	}
	fs.close();
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::parseInput(int argc, char **argv)
{
	if (argc != 2)
		throw std::runtime_error("Error: could not open file.\n");
	std::string	line;
	std::fstream	fs(argv[1]);
	if (!fs.is_open())
		throw std::runtime_error("Error: could not open file.\n");
	std::getline(fs, line);
	// char	seperator = line.find("|");
	// if (seperator == std::string::npos)

	while (!std::getline(fs, line))
	{
		this->_input.insert(this->parseLine(line));
	}
	fs.close();
}
