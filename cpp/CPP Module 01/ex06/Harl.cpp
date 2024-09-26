#include "Harl.hpp"

void	Harl::debug(void)
{
	cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << endl;
	cout << "I really do!" << endl;
}

void	Harl::info(void)
{
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money." << endl;
	cout << "You didn’t put enough bacon in my burger!" << endl;
	cout << "If you did, I wouldn’t be asking for more!" << endl;
}

void	Harl::warning(void)
{
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free." << endl;
	cout << "I’ve been coming for years whereas you started working here since last month." << endl;
}

void	Harl::error(void)
{
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable!" << endl;
	cout << "I want to speak to the manager now." << endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}
void    Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	int i = 0;
	while(i < 4)
	{
		if(level == levels[i])
			break;
		i++;
	}
	switch(i)
	{
		case(0):
		{
			(this->*functions[0])();
			break;
		}
		case(1):
		{
			(this->*functions[1])();
			break;
		}
		case(2):
		{
			(this->*functions[2])();
			break;
		}
		case(3):
		{
			(this->*functions[3])();
			break;
		}
	}
	return ;
}

// array of function pointers explanation::
// basically make an array of pointers which point to different functions
// first void is to specify functions return void
// second (void) is to specify functions take in void
