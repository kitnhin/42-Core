#include "Bureaucrat.hpp"

// void testft()
// {
// 	char *test = NULL;
// 	// if(test == NULL)
// 	// 	throw std::invalid_argument("test exception");
// 	char c = test[1];
// }

// int main()
// {
// 	try
// 	{
// 		testft();
// 	}
// 	catch(std::exception &e)
// 	{
// 		cout << e.what() << endl;
// 	}
// 	return 0;
// }	

int main()
{
	try
	{
		cout << endl;
		Bureaucrat Yuki("Yuki", 1);
		Bureaucrat Alya("Alya", 150);
		cout << Alya;
		cout << Yuki;
		cout << "Expected: none\n" << endl;
	}
	catch(const std::exception& e) //no exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		cout << "Level: 0" << endl;
		cout << "Expected: too high" << endl;
		Bureaucrat Alya("Alya", 0);
	}
	catch(const std::exception& e) // grade too high exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		cout << "Level: 151" << endl;
		cout << "Expected: too low" << endl;
		Bureaucrat Yuki("Yuki", 151);
	}
	catch(const std::exception& e) // grade too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		cout << "Level: 151 and 0" << endl;
		cout << "Expected: too low" << endl;
		Bureaucrat Yuki("Yuki", 151);
		Bureaucrat Alya("Alya", 0);
	}
	catch(const std::exception& e) // grade low exception caught (first exception thrown)
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		cout << "Level: 0" << endl;
		cout << "Expected: too high" << endl;
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
		cout << "|Test decrement grade:|\n" << endl;
		cout << "Normal test: " << endl;
		Bureaucrat Alya("Alya", 5);
		cout << "Before: " << Alya;
		Alya.decrementGrade();
		cout << "After: " << Alya << endl;

		cout << "Test invalid decrement: " << endl;
		Bureaucrat Yuki("Yuki", 150);
		Yuki.decrementGrade();
	}
	catch(const std::exception& e) // grade too low exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		cout << "|Test increment grade:|\n" << endl;
		cout << "Normal test: " << endl;
		Bureaucrat Alya("Alya", 5);
		cout << "Before: " << Alya;
		Alya.incrementGrade();
		cout << "After: " << Alya << endl;

		cout << "Test invalid increment:" << endl;
		Bureaucrat Yuki("Yuki", 1);
		Yuki.incrementGrade();
	}
	catch(const std::exception& e) // grade too high exception caught
	{
		std::cerr << e.what() << endl;
	}
}