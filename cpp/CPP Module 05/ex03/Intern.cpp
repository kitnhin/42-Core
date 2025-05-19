#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

AForm *make_shrubbery_form(string target)
{
	return(new ShrubberyCreationForm(target));
}

AForm *make_robotomy_form(string target)
{
	return(new RobotomyRequestForm(target));
}

AForm *make_presidential_form(string target)
{
	return(new PresidentialPardonForm(target));
}

char const *Intern::InvalidNameException::what() const throw()
{
	return ("Invalid form rip");
}

AForm *Intern::makeForm(string name, string target)
{
	string names[4] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*functions[])(string) = {make_shrubbery_form, make_robotomy_form, make_presidential_form};
	for(int i = 0; i < 4; i++)
	{
		if(name.compare(names[i]) == 0)
		{
			cout << "Intern created a " << name << " form" << endl; 
			return((*functions[i])(target));
		}
	}
	throw Intern::InvalidNameException();
}