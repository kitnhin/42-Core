#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;

class AForm
{
	private:
	const string	name;
	bool			sign;
	const int		sign_grade_req;
	const int		exec_grade_req;

	public:
	AForm();
	AForm(const AForm &obj);
	virtual ~AForm();
	AForm &operator=(const AForm &obj);

	void	beSigned(Bureaucrat &bureaucrat);
	AForm(string _name, int _sign_grade_req, int _exec_grade_req);
	void	execute(Bureaucrat const &executer) const;
	string	getName() const;
	bool	getSign() const;
	int		get_sign_grade_req() const;
	int		get_exec_grade_req() const;
	virtual void	exec() const = 0;
	//need virtual =0 for abstract class (Not instantiable, cant create objects directly from it)

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &os, AForm const &obj);

#endif
