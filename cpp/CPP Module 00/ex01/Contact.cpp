#include "Phonebook.hpp"

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
	cout << format_string(firstname) << "|";
    cout << format_string(lastname) << "|";
    cout << format_string(nickname) << "|" << endl;
}

void	Contact::display_full_contact()
{
	cout << "Firstname : " << firstname << endl;
	cout << "Lastname : " << lastname << endl;
	cout << "Nickname : " << nickname << endl;
	cout << "Phonenumber : " << phonenum << endl;
	cout << "Darkest Secret : " << secret << endl;
}

void	Contact::setcontact(string firstname, string lastname, string nickname, string phonenum, string secret)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phonenum = phonenum;
	this->secret = secret;
}
