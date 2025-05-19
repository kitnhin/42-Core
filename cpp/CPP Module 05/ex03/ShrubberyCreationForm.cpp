#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("none"){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

string ShrubberyCreationForm::getTarget()
{
	return(this->target);
}

void	ShrubberyCreationForm::exec() const
{
	string outfile = this->target + "_shrubbery";
	ofstream out(outfile.c_str());
	for(int i = 0; i < 2; i++)
	{
		out << "     /\\     " << endl;
		out << "    /  \\    " << endl;
		out << "   /    \\   " << endl;
		out << "  /      \\  " << endl;
		out << " /        \\ " << endl;
		out << "------------ " << endl;
		out << "     ||      " << endl;
		out << "     ||      " << endl;
		out << endl;
	}
	out.close();
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &obj)
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