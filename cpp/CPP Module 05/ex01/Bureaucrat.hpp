#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

using std::string;
using std::cout;
using std::endl;
using std::exception;

class Form;

class Bureaucrat
{
	private:
	string	name;
	int		grade;

	public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &obj);

	string	getName() const;
	int		getGrade() const;
	Bureaucrat(string name, int grade);
	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj);

#endif