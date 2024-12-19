#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	//successful tests
	cout << endl;
	try
	{
		Intern *miyabi = new Intern();
		Bureaucrat *belle = new Bureaucrat("belle", 1);
		AForm *ellen = miyabi->makeForm("shrubbery creation", "mom");
		belle->signForm(*ellen);
		ellen->execute(*belle);
		cout << endl;
		delete miyabi;
		delete belle;
		delete ellen;
	}
	catch(const std::exception& e) // successfully exec form
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Intern *miyabi = new Intern();
		Bureaucrat *belle = new Bureaucrat("belle", 1);
		AForm *ellen = miyabi->makeForm("robotomy request", "mom");
		belle->signForm(*ellen);
		ellen->execute(*belle);
		cout << endl;
		delete miyabi;
		delete belle;
		delete ellen;
	}
	catch(const std::exception& e) // successfully exec form
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Intern *miyabi = new Intern();
		Bureaucrat *belle = new Bureaucrat("belle", 1);
		AForm *ellen = miyabi->makeForm("presidential pardon", "mom");
		belle->signForm(*ellen);
		ellen->execute(*belle);
		cout << endl;
		delete miyabi;
		delete belle;
		delete ellen;
	}
	catch(const std::exception& e) // successfully exec form
	{
		std::cerr << e.what() << endl;
	}
	
	//failure test
	try
	{
		Intern *miyabi = new Intern();
		Bureaucrat *belle = new Bureaucrat("belle", 1);
		AForm *ellen = miyabi->makeForm("no such name", "mom");
		belle->signForm(*ellen);
		ellen->execute(*belle);
		cout << endl;
		delete miyabi;
		delete belle;
		delete ellen;
	}
	catch(const std::exception& e) // exception caught yayyyy
	{
		std::cerr << e.what() << endl;
	}
}