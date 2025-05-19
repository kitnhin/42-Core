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
		AForm *ellen = miyabi->makeForm("shrubbery creation", "castorice");
		belle->signForm(*ellen);
		belle->executeForm(*ellen);
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
		AForm *ellen = miyabi->makeForm("robotomy request", "castorice");
		belle->signForm(*ellen);
		belle->executeForm(*ellen);
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
		AForm *ellen = miyabi->makeForm("presidential pardon", "castorice");
		belle->signForm(*ellen);
		belle->executeForm(*ellen);
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
	Intern *miyabi = new Intern();
	Bureaucrat *belle = new Bureaucrat("belle", 1);
	try
	{
		AForm *ellen = miyabi->makeForm("no such name", "castorice");
		belle->signForm(*ellen);
		belle->executeForm(*ellen);
		cout << endl;
	}
	catch(const std::exception& e) // exception caught yayyyy
	{
		std::cerr << e.what() << endl;
	}
	delete miyabi;
	delete belle; // knn have to put this outside somemore if not will have mem leaks 
}