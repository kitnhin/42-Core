#include "BitcoinExchange.hpp"

using std::istringstream;


//=================== utils ====================/

float	str_to_float(string str)
{
	istringstream iss(str);
	float ret;
	
	//cout << str << endl;
	iss >> ret;
	if(iss.fail())
		throw std::runtime_error("str_to_float failed");
	return ret;
}

int	str_to_int(string str)
{
	istringstream iss(str);
	int ret;
	
	iss >> ret;
	if(iss.fail())
		throw std::runtime_error("str_to_float failed");
	return ret;
}

bool is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


//=================== actually bitexchange ====================/

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
		size_t commapos = line.find_first_of(",");
		if(commapos == string::npos)
		{
			cout << "cannot find comma in line: " << line << endl;
			continue;
		}
		string extracted_date = line.substr(0, commapos);
		string extracted_value = line.substr(commapos + 1, line.length() - commapos);
	
		float extracted_value_float = str_to_float(extracted_value);
		this->data.insert(std::make_pair(extracted_date, extracted_value_float));
	}
}

int	validate_line(string line)
{
	//cout << line << endl;
	for(size_t i = 0; i < line.length(); i++)
	{
		if(i == 13 && line[i] == '-') //check - anywhere other than at neg value
			continue;
		if(i > 13 && line[i] == '.') //check . anywhere other than at decimal
			continue;
		if(i == 11 && line[i] != '|') //check | in " | "
		{
			//cout << "test1" << endl;
			return 1;
		}
		else if((i == 10 || i == 12) && line[i] != ' ') //check spaces in " | "
		{
			//cout << "test2" << endl;
			return 1;
		}
		else if((i == 4 || i == 7) && line[i] != '-') //check dash in date
		{
			//cout << "test3" << endl;
			return 1;
		}
		else if((i != 4 && i != 7 && (i < 10 || i > 12)) && !isdigit(line[i]))
		{
			//cout << "test4 " << i << endl;
			return 1;
		}
	}
	try
	{
		int month = str_to_int(line.substr(5,2));
		int day = str_to_int(line.substr(8,2));
		int year = str_to_int(line.substr(0, 4));

		//cout << "day: " << day << " month: " << month << " year: " << year << endl;
		if(month < 1 || month > 12)
			return 1;

		int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(is_leap_year(year))
			days_in_month[2] = 29;
		if(day < 1 || day > days_in_month[month])
			return 1;
	}
	catch(const std::exception& e)
	{
		return 1;
	}
	return 0;
}

float getFloat(string line)
{

	float res = str_to_float(line);
	if(res < 0)
	{
		cerr << "Error: not a positive number" << endl;
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
	if(it == data.begin())
	{
		cerr << "Error: date too small rip" << endl;
		return -1;
	}
	it--;
	return(it->second);
}

void	BitcoinExchange::process_input(string inputPath)
{
	string	line;
	string	extracted_date;
	string	extracted_value;
	float	extracted_value_float;
	float	rate;
	std::ifstream inFile(inputPath.c_str());

	if(!inFile.is_open())
	{
		std::cerr << "unable to open input file haih wat mao u doin" << endl;
		return ;
	}

	//get header
	getline(inFile, line);
	if(line == "")
		cerr << "Error: file empty" << endl;
	else if(line != "date | value")
		cerr << "Error: bad header => " << line << endl;
	while(getline(inFile,line))
	{
		if(line == "")
			continue;
		if(validate_line(line) != 0)
		{
			cerr << "Error: bad input => "<< line << endl;
			continue ;
		}
		extracted_date = line.substr(0,10);
		extracted_value = line.substr(13, line.length() - 1);
		//cout << "date: " << extracted_date << " value: " << extracted_value << endl;
		extracted_value_float = getFloat(extracted_value);
		rate = getRate(extracted_date);
		if (extracted_value_float != -1 && rate != -1)
			cout << extracted_date << " => " << extracted_value << " = " << extracted_value_float * rate << endl;
	}
}
