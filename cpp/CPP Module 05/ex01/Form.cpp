#include "Form.hpp"

//constructors::

//need to write like this cuz const vars
Form::Form() : name("no name"), sign(false), sign_grade_req(50), exec_grade_req(50)
{
}

Form::Form(const Form &obj) : name(obj.name), sign(obj.sign), sign_grade_req(obj.sign_grade_req), exec_grade_req(obj.exec_grade_req)
{
}

Form::Form(string _name, int _sign_grade_req, int _exec_grade_req) : name(_name), sign(false), sign_grade_req(_sign_grade_req), exec_grade_req(_exec_grade_req)
{
	if(_sign_grade_req < 1 || _exec_grade_req < 1)
		throw Form::GradeTooHighException();
	else if(_sign_grade_req > 150 || _exec_grade_req > 150)
		throw Form::GradeTooLowException();
}
//destructor
Form::~Form()
{
}

//CAO
Form &Form::operator=(const Form &obj)
{
	if(this == &obj)
		return *this; // need this to prevent self assign
	*this = Form(obj);
	return *this;
}

//getters
string	Form::getName() const
{
	return(this->name);
}

bool	Form::getSign() const
{
	return(this->sign);
}

int	Form::get_sign_grade_req() const
{
	return(this->sign_grade_req);
}

int Form::get_exec_grade_req() const
{
	return(this->exec_grade_req);
}

//exceptions
char const *Form::GradeTooLowException::what() const throw()
{
	return ("[Form] Grade too low\n");
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("[Form] Grade too high\n");
}

//other fts
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->sign_grade_req)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &obj)
{
	os << obj.getName();
	if(obj.getSign() == true)
		os << " has been signed. ";
	else
		os << " has not been signed. ";
	os << "Minimum grade to sign: " << obj.get_sign_grade_req();
	os << " Minimum grade to exec: " << obj.get_exec_grade_req();
	return os;
}