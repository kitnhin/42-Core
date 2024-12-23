#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if(this == &obj)
		return(*this);
	this->data = obj.data;
	return(*this);
}

void	BitcoinExchange::getData()
{
	string	line;
	string	extracted_date;
	string	extracted_value;

	std::ifstream datafile("data.csv");
	if(!datafile.is_open())
	{
		std::cerr << "unable to open data file rip" << endl;
		return;
	}
	getline(datafile, line); // skip header
	while(getline(datafile, line))
	{
		extracted_date.clear();
    	extracted_value.clear();
		std::copy(line.begin(), std::find(line.begin(), line.end(), ','), std::back_inserter(extracted_date));
		std::copy(std::find(line.begin(), line.end(), ',') + 1, line.end(), std::back_inserter(extracted_value));
		//back_inserter is just push back but for strings
		//couldve used substr but wanted to try smth else rip nv again this is so mafan
	
		float extracted_value_float = stof(extracted_value);
		this->data.insert(std::make_pair(extracted_date, extracted_value_float));
	}
}

int	validate_line(string line)
{
	if(line.find("|") != 11)
	{
		cerr << "Error: bad input => "<< line << endl;
		return 1;
	}
	int month = stoi(line.substr(5,2));
	int day = stoi(line.substr(8,2));
	if(month < 1 || month > 12)
	{
		cerr << "Error: bad input => "<< line << endl;
		return 1;
	}
	if(day < 1 || day > 31)
	{
		cerr << "Error: bad input => "<< line << endl;
		return 1;
	}
	return 0;
}

float getFloat(string line)
{

	float res = stof(line);
	if(res < 0)
	{
		cerr << "Error: not a posive number" << endl;
		return (-1);
	}
	if(res > 1000)
	{
		cerr << "Error: too large a number" << endl;
		return (-1);
	}
	return res;
}

float	BitcoinExchange::getRate(string line)
{
	map<string,float>::iterator it;

	it = data.upper_bound(line);
	it--;
	if(it == data.end())
	{
		cerr << "date not found rip" << endl;
		return -1;
	}
	return(it->second);
}

void	BitcoinExchange::process_input(string inputPath)
{
	string	line;
	string	extracted_date;
	string	extracted_value;
	float	extracted_value_float;
	float	rate;
	std::ifstream inFile(inputPath);

	if(!inFile.is_open())
	{
		std::cerr << "unable to open input file haih wat mao u doin" << endl;
		return ;
	}
	while(getline(inFile,line))
	{
		if(validate_line(line) != 0)
			continue ;
		extracted_date = line.substr(0,10);
		extracted_value = line.substr(13, line.length() - 1);
		extracted_value_float = getFloat(extracted_value);
		rate = getRate(extracted_date);
		if (extracted_value_float != -1 && rate != -1)
			cout << extracted_date << " => " << extracted_value << " = " << extracted_value_float * rate << endl;
	}
}