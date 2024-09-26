#include "Harl.hpp"

void	Harl::debug(void)
{
	cout << "[ DEBUG ]" << endl;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << endl;
}

void	Harl::info(void)
{
	cout << "[ INFO ]" << endl;
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void	Harl::warning(void)
{
	cout << "[ WARNING ]" << endl;
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void	Harl::error(void)
{
	cout << "[ ERROR ]" << endl;
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

Harl::Harl()
{
	cout << "Harl is made :)" << endl;
}

Harl::~Harl()
{
	cout << "Harl destroyed :(" << endl;
}
void    Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};
	for(int i = 0; i < 4; i++)
	{
		if(level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	cout << "invalid input bruh" << endl;
	return ;
}

// array of function pointers explanation::
// basically make an array of pointers which point to different functions
// first void is to specify functions return void
// second (void) is to specify functions take in void
