#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("none") {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	AForm::operator=(obj);
	this->target = obj.target;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

string RobotomyRequestForm::getTarget()
{
	return(this->target);
}

void	RobotomyRequestForm::exec() const
{
	int wait = 700000;
	cout << "*drilling noises*" << endl;
	usleep(wait);
	cout << "BUzz" << endl;
	usleep(wait);
	cout << "bUzz" << endl;
	usleep(wait);

	//randomness
	std::srand(std::time(0));
	if(std::rand() % 2)
		cout << "robotomized successful yay" << endl;
	else
		cout << "looks like ure even losing 5050 here thats just sadness" << endl; 
}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &obj)
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