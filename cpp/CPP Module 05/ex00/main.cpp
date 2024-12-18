#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Yuki("Yuki", 1);
		Bureaucrat Alya("Alya", 150);
	}
	catch(const std::exception& e) //no exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Alya("Alya", 0);
	}
	catch(const std::exception& e) // grade too high exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Yuki("Yuki", 151);
	}
	catch(const std::exception& e) // grade too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Yuki("Yuki", 151);
		Bureaucrat Alya("Alya", 0);
	}
	catch(const std::exception& e) // grade low exception caught (first exception thrown)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Yuki("Yuki", 0);
		cout << "test" << endl;
		cout << "test" << endl;
	}
	catch(const std::exception& e) // after exception is caught nth is done
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Yuki("Yuki", 150);
		Yuki.decrementGrade();
	}
	catch(const std::exception& e) // grade too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Bureaucrat Yuki("Yuki", 1);
		Yuki.incrementGrade();
	}
	catch(const std::exception& e) // grade too high exception caught
	{
		std::cerr << e.what() << endl;
	}
	Bureaucrat Yuki("Yuki", 10);
	cout << Yuki << endl;
}