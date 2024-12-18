#include "Form.hpp"

	// public:
	// Form();
	// Form(const Form &obj);
	// ~Form();
	// Form &operator=(const Form &obj);

	// void	beSigned();
	// string	getName();
	// bool	getSign();
	// int		get_sign_grade_req();
	// int		get_exec_grade_req();


//need to write like this cuz const vars
Form::Form() : name("no name"), sign(false), sign_grade_req(50), exec_grade_req(50)
{
}

Form::Form(const Form &obj) : name(obj.name), sign(obj.sign), sign_grade_req(obj.sign_grade_req), exec_grade_req(obj.exec_grade_req)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &obj)
{
	if(this == &obj)
		return *this; // need this to prevent self assign
	*this = Form(obj);
	return *this;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->sign_grade_req)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

Form::Form(string _name, int _sign_grade_req, int _exec_grade_req) : name(_name), sign(false), sign_grade_req(_sign_grade_req), exec_grade_req(_exec_grade_req)
{
	if(_sign_grade_req < 1 || _exec_grade_req < 1)
		throw Form::GradeTooHighException();
	else if(_sign_grade_req > 150 || _exec_grade_req > 150)
		throw Form::GradeTooLowException();
}

string	Form::getName() const
{
	return(this->name);
}

bool	Form::getSign()
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

char const *Form::GradeTooLowException::what() const throw()
{
	return ("[Form] Grade too low");
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("[Form] Grade too high");
}
