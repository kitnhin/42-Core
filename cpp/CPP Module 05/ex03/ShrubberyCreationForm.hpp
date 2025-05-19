#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

using std::ofstream;

class ShrubberyCreationForm : public AForm
{
	private:
	string target;

	public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &obj);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

	ShrubberyCreationForm(string target);
	void	exec() const;
	string	getTarget();
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm const &obj);

#endif
