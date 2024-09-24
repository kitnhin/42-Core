#include <iostream>
#include <string>

using std::string;

class Contact
{
	private:

	string _firstname;
	string _lastname;
	string _nickname;
	string _phonenum;
	string _secret;

	public:
	void	setcontact(string firstname, string lastname, string nickname, string phonenum, string secret);
	void	display_contact_short(int index);
	void	display_full_contact();
};

class Phonebook
{
	private:

	Contact _contact[8];

	public:
	int		add_contact(int index);
	void	do_search(int curr_index);

};