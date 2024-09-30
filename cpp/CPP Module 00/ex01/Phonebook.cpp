#include "Phonebook.hpp"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

int	Phonebook::add_contact(int index)
{
	string firstname;
	string lastname;
	string nickname;
	string phonenum;
	string secret;

	cout << "Pls enter first name: ";
	getline(cin, firstname);
	cout << "Pls enter last name: ";
	getline(cin, lastname);
	cout << "Pls enter nickname: ";
	getline(cin, nickname);
	cout << "Pls enter phone number: ";
	getline(cin, phonenum);
	cout << "Pls enter darkest secret: ";
	getline(cin, secret);

	if (firstname.empty() || lastname.empty() || nickname.empty() || phonenum.empty() || secret.empty())
	{
		cout << "U think u very funny ah, no empty fields pls" << endl;
		return 1;
	}
	else
	{
		_contact[index].setcontact(firstname, lastname, nickname, phonenum, secret);
		return 0;
	}

}

void	Phonebook::do_search(int curr_index)
{
	int index;
	string str;
	cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << endl;
	cout << "|----------|----------|----------|----------|" << endl;
	for(int i = 0; i < 8 ; i++)
		_contact[i].display_contact_short(i);
	cout << "Which contact info u want?" << endl;
	getline(cin, str);
	index = atoi(str.c_str()) - 1; // used this cuz idk how to handle error for stoi lol
	if(index < 0 || index > curr_index)
		cout << "Invalid input bruh, exiting search" << endl;
	else
		_contact[index].display_full_contact();
}
