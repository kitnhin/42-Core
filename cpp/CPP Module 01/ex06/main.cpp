#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "bruh follow the syntax pls. syntax : <string>" << endl;
		return 1;
	}
	Harl harl;
	string strings[] = {"debug", "info", "warning", "error"};
	srand((unsigned int)(time(0)));
	int k = 0;
	while(k < 4)
	{
		if(strings[k] == argv[1])
			break;
		k++;
	}
	if(k == 4)
	{
		cout << "[ Probably complaining about insignificant problems ]" << endl;
		return 0;
	}
	for(int j = 0; j < 5; j++)
	{
		int i = rand() % 4;
		if(i >= k)
		{
			harl.complain(strings[i]);
			cout << endl;
		}
	}
}

// im not actually sure wat the subject wants, i hope its like this lol