#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->name = "unknown";
	this->grade = 100;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
	this->name = obj.name;
	this->grade = obj.grade;
	return (*this);
}

string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat] Grade too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat] Grade too low");
}

Bureaucrat::Bureaucrat(string name, int grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->name = name;
		this->grade = grade;
	}
}

void	Bureaucrat::decrementGrade()
{
	if((this->grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

void	Bureaucrat::incrementGrade()
{
	if((this->grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	return(os << obj.getName() << " has a grade " << obj.getGrade() << endl);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		cout << this->name << " couldn’t sign " << form.getName() << " because grade too low" << endl;
	}
	if(form.getSign() == true)
		cout << this->name << " signed " << form.getName() << endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		cout << this->name << " failed the form execution :(" << endl;
		return;
	}
	cout << this->name << " successfully executed the form" << endl;
}