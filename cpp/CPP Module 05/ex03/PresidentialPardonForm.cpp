#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("none") {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

string PresidentialPardonForm::getTarget()
{
	return(this->target);
}

void	PresidentialPardonForm::exec() const
{
	cout << this->target << " has been pardoned by Zaphod Beeblebrox" << endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &obj)
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
