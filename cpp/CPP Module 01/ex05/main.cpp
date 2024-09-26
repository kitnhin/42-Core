#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Harl harl;

	string strings[] = {"debug", "info", "warning", "error"};
	srand((unsigned int)(time(0)));
	for(int j = 0; j < 10; j++)
	{
		int i = rand() % 4;
		harl.complain(strings[i]);
		cout << endl;
	}
}

//notes for rand()
//rand() actually contains a very long list of (seemingly random) numbers, but its not actually random its predetermined
//srand() helps chooses which number it starts from, so the number u get is always different
//therefore if u dont do srand(), the sequence will start from 1 and continue, so ure gonna get the first few numbers of the sequence everytime
//we use time(0) because the time is always changing, so seed always change, so number always change.