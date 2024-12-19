#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
	AForm	*makeForm(string name, string target);

	Intern();
	Intern(const Intern &obj);
	~Intern();
	Intern &operator=(const Intern &obj);

	class InvalidNameException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif