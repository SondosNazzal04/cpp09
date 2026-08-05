/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snazzal <snazzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:34:55 by snazzal           #+#    #+#             */
/*   Updated: 2026/08/05 15:44:52 by snazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str, const std::string &whitespace) {
	const size_t first = str.find_first_not_of(whitespace);

	if (first == std::string::npos)
		return "";
	const size_t last = str.find_last_not_of(whitespace);
	return str.substr(first, (last - first) + 1);
}

bool	isnum(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.')
			return false;
	}
	return true;
}

std::pair <std::string, double>	BitcoinExchange::parseLine(const std::string &line, char seperator)
{
	std::stringstream	ss;
	double				value;
	size_t				seperatorPos = line.find(seperator);
	if (seperatorPos == std::string::npos)
		throw std::runtime_error("bad input\n");
	std::string			date = line.substr(0, seperatorPos);
	date = trim(date, " \t");
	if (date.empty())
		throw std::runtime_error("bad input\n");
	if (!date.empty() && date[date.length() - 1] == ' ')
		date.erase(date.length() - 1);
	std::string			valueStr = line.substr(seperatorPos + 1);
	valueStr = trim(valueStr, " \t");
	if (!isnum(valueStr))
		throw std::runtime_error("bad input\n");
	if (valueStr.empty())
		throw std::runtime_error("bad input\n");
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
			throw std::runtime_error("bad input\n");
	}
	while (std::getline(fs, line))
	{
		if (line.empty())
			continue;
		this->_database.insert(this->parseLine(line, seperator));
	}
	fs.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_database = other._database;
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_database = other._database;
	return *this;
}



//check invalid dates
void	BitcoinExchange::checkInput(std::pair <std::string, double> input)
{
	if (!isnum(input.first))
		throw std::runtime_error("bad input\n");
	if (input.first < _database.begin()->first)
		throw std::runtime_error("date too early!");
	if (input.second < 0)
		throw std::runtime_error("not a positive value");
	if (input.second > 1000)
		throw std::runtime_error("too large a number.");

	size_t firstDash = input.first.find('-');
	size_t secondDash = input.first.find('-', firstDash + 1);

	std::string year = input.first.substr(0, firstDash);
	std::string month = input.first.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string day = input.first.substr(secondDash + 1);
	if (year.length() > 4 || month.length() > 2 || day.length() > 2)
		throw std::runtime_error("invalid date");
	if (month > "12" || month < "01")
		throw std::runtime_error("invalid month");
	if (day > "31" || day < "01")
		throw std::runtime_error("invalid day");
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
			throw std::runtime_error("bad input\n");
	}

	size_t	seperatorPos = line.find(seperator);
	if (seperatorPos == std::string::npos)
		throw std::runtime_error("bad input\n");
	std::string	date = line.substr(0, seperatorPos);
	date = trim(date, " \t");
	if (date.empty() || date != "date")
		throw std::runtime_error("bad input\n");
	std::string	valueStr = line.substr(seperatorPos + 1);
	valueStr = trim(date, " \t");
	if (valueStr.empty() || valueStr != "value")
		throw std::runtime_error("bad input\n");

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
			if ("bad input\n" == error)
				std::cerr << "bad input => " << line << '\n';
			else
				std::cerr << e.what() << '\n';
		}

	}
	fs.close();
}
