#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form Elaina("Elaina", 50,50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form Elaina("Elaina", -1, 50);
	}
	catch(const std::exception& e) // too high exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form Elaina("Elaina", 1000, 50);
	}
	catch(const std::exception& e) // too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form Elaina("Elaina", 10, 1000);
	}
	catch(const std::exception& e) // too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form Elaina("Elaina", 10, 50);
		Bureaucrat Miku("Miku", 10);
		Miku.signForm(Elaina);
	}
	catch(const std::exception& e) // sign success
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Form Elaina("Elaina", 1, 50);
		Bureaucrat Miku("Miku", 10);
		Miku.signForm(Elaina);
	}
	catch(const std::exception& e) // too low exception caught in Bureaucrat sign function
	{
		std::cerr << e.what() << endl;
	}
	Form Elaina("Elaina", 1, 50);
	Bureaucrat Miku("Miku", 10);
	Miku.signForm(Elaina);
	cout << Elaina << endl;
	Form Firefly("Firefly",1,1);
	cout << Firefly << endl;
}