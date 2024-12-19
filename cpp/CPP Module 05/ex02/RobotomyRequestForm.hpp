#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

using std::ofstream;

class RobotomyRequestForm : public AForm
{
	private:
	string target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &obj);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

	RobotomyRequestForm(string target);
	void	exec() const;
	string	getTarget();
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm const &obj);

#endif
