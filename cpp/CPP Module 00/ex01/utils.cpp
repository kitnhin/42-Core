#include "phonebook.hpp"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

string format_string(string str)
{
	string res;
	if(str.length() > 10)
	{
		res = str.substr(0, 9) + '.';
		return res;
	}
	else
	{
		int i = 10 - str.length();
		res = str;
		for(int j = 0 ; j < i ; j++)
			res = ' ' + res;
		return res;
	}
}

void	Contact::display_contact_short(int index)
{
	cout << "|         " << index + 1 << "|";
	cout << format_string(_firstname) << "|";
    cout << format_string(_lastname) << "|";
    cout << format_string(_nickname) << "|" << endl;
}

void	Contact::display_full_contact()
{
	cout << "Firstname : " << _firstname << endl;
	cout << "Lastname : " << _lastname << endl;
	cout << "Nickname : " << _nickname << endl;
	cout << "Phonenumber : " << _phonenum << endl;
	cout << "Darkest Secret : " << _secret << endl;
}

void	Contact::setcontact(string firstname, string lastname, string nickname, string phonenum, string secret)
{
	_firstname = firstname;
	_lastname = lastname;
	_nickname = nickname;
	_phonenum = phonenum;
	_secret = secret;
}
