#include "Harl.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	Harl harl;

	string strings[] = {"debug", "info", "warning", "error"};
	srand((unsigned int)(time(0)));
	for(int j = 0; j < 5; j++)
	{
		int i = rand() % 4;
		harl.complain(strings[i]);
		cout << endl;
	}

	cout << "\nexplaination for the gacha in gacha systems:\n\n" << endl;
	cout << "first number:" << rand() << endl;
	cout << "second number:" << rand() << endl;
	cout << "third number:" << rand() << endl;

}

//notes for rand()
//rand() actually contains a very long list of (seemingly random) numbers, but its not actually random its predetermined
//srand() helps chooses which number it starts from, so the number u get is always different
//therefore if u dont do srand(), the sequence will start from 1 and continue, so ure gonna get the first few numbers of the sequence everytime
//we use time(0) because the time is always changing, so seed always change, so number always change.