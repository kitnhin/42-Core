#include "Phonebook.hpp"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

int	main()
{
	string line;
	Phonebook phonebook;
	int index = -1;
	while(1)
	{
		cout << "Enter a cmd:" << endl;
		std::getline(cin, line);
		if(line == "ADD")
		{
			index = (index + 1) % 8;
			if(phonebook.add_contact(index) == 1)
				index--;
		}
		else if(line == "SEARCH")
			phonebook.do_search(index);
		else if(line == "EXIT")
			break;
		else
			cout << "enter ADD SEARCH OR EXIT ONLY" << endl;
	}
	return 0;
}
