#ifndef BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::string;
using std::endl;
using std::cout;
using std::map;
using std::getline;
using std::cerr;

//ai says use map container and apparently all of the solutions oso use this wth then i use oso la
//cuz it has key value pair (date and value)

class BitcoinExchange
{
	private:
		std::map<string, float> data;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange &operator=(const BitcoinExchange &obj);

		void	getData();
		void	process_input(string inputPath);
		float	getRate(string line);
};


#endif