#include "AForm.hpp"

//need to write like this cuz const vars
AForm::AForm() : name("no name"), sign(false), sign_grade_req(50), exec_grade_req(50)
{
}

AForm::AForm(const AForm &obj) : name(obj.name), sign(obj.sign), sign_grade_req(obj.sign_grade_req), exec_grade_req(obj.exec_grade_req)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &obj)
{
	if(this == &obj)
		return *this; // need this to prevent self assign
	this->sign = obj.sign; // actually only have one non const var haih
	return *this;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->sign_grade_req)
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
}

AForm::AForm(string _name, int _sign_grade_req, int _exec_grade_req) : name(_name), sign(false), sign_grade_req(_sign_grade_req), exec_grade_req(_exec_grade_req)
{
	if(_sign_grade_req < 1 || _exec_grade_req < 1)
		throw AForm::GradeTooHighException();
	else if(_sign_grade_req > 150 || _exec_grade_req > 150)
		throw AForm::GradeTooLowException();
}

string	AForm::getName() const
{
	return(this->name);
}

bool	AForm::getSign() const
{
	return(this->sign);
}

int	AForm::get_sign_grade_req() const
{
	return(this->sign_grade_req);
}

int AForm::get_exec_grade_req() const
{
	return(this->exec_grade_req);
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return ("[AForm] Grade too low");
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return ("[AForm] Grade too high");
}

char const *AForm::FormNotSignedException::what() const throw()
{
	return ("[AForm] Form not signed");
}

std::ostream &operator<<(std::ostream &os, AForm const &obj)
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

void	AForm::execute(Bureaucrat const &executer) const
{
	if(this->sign == false)
		throw FormNotSignedException();
	else if(executer.getGrade() > this->exec_grade_req)
		throw GradeTooLowException();
	else
	{
		cout << executer.getName() << " executed " << this->name << endl;
		this->exec();
	}
}