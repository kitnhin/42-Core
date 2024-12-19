#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

using std::ofstream;

class PresidentialPardonForm : public AForm
{
	private:
		string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

		PresidentialPardonForm(string target);
		void	exec() const;
		string	getTarget();
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm const &obj);

#endif
