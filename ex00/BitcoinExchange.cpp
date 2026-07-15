/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:34:55 by snazzal           #+#    #+#             */
/*   Updated: 2026/07/15 13:23:07 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::pair <std::string, double>	BitcoinExchange::parseLine(const std::string &line, char seperator)
{
	std::stringstream	ss;
	double				value;
	size_t				seperatorPos = line.find(seperator);
	if (seperatorPos == std::string::npos)
	{
		throw std::runtime_error("seperator not found\n");
	}
	std::string			date = line.substr(0, seperatorPos);
	if (!date.empty() && date[date.length() - 1] == ' ')
		date.erase(date.length() - 1);
	std::string			valueStr = line.substr(seperatorPos + 1);
	ss << valueStr;
	ss >> value;
	return std::make_pair(date, value);
}

BitcoinExchange::BitcoinExchange()
{
	std::string		line;
	std::fstream	fs("data.csv");
	if (!fs.is_open())
		throw std::runtime_error("Error: Failed to open file!");

	std::getline(fs, line);
	char seperator = ',';
	size_t seperatorIdx = line.find(seperator);
	if (seperatorIdx == std::string::npos)
	{
		seperator = '|';
		seperatorIdx = line.find(seperator);
		if (seperatorIdx == std::string::npos)
			throw std::runtime_error("seperator not found\n");
	}
	while (std::getline(fs, line))
	{
		if (line.empty())
			continue;
		// this->parseLine(line);
		this->_database.insert(this->parseLine(line, seperator));
	}
	fs.close();
}
//check invalid dates
void	BitcoinExchange::checkInput(std::pair <std::string, double> input)
{
	if (input.first < "2009-01-01")
		throw std::runtime_error("date too early!");
	if (input.second < 0)
		throw std::runtime_error("not a positive value");
	if (input.second > INT_MAX)
		throw std::runtime_error("too large a number.");
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

	char seperator = ',';
	size_t seperatorIdx = line.find(seperator);
	if (seperatorIdx == std::string::npos)
	{
		seperator = '|';
		seperatorIdx = line.find(seperator);
		if (seperatorIdx == std::string::npos)
			throw std::runtime_error("seperator not found\n");
	}

	while (std::getline(fs, line))
	{
		try
		{
			std::pair <std::string, double> input = this->parseLine(line, seperator);
			this->checkInput(input);
			std::map <std::string, double>::iterator it = this->_database.upper_bound(input.first);
			it--;
			double answer = it->second * input.second;
			std::cout << input.first << " => " << input.second << " => " << answer << "\n";
		}
		catch(const std::exception& e)
		{
			std::string error = e.what();
			std::cerr << "Error: ";
			if ("seperator not found\n" == error)
				std::cerr << "bad input => " << line << '\n';
			else
				std::cerr << e.what() << '\n';
		}

	}
	fs.close();
}
