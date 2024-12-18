#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

using std::string;

class Bureaucrat;


class Form
{
	private:
	const string	name;
	bool			sign;
	const int		sign_grade_req;
	const int		exec_grade_req;

	public:
	Form();
	Form(const Form &obj);
	~Form();
	Form &operator=(const Form &obj);

	void	beSigned(Bureaucrat &bureaucrat);
	Form(string _name, int _sign_grade_req, int _exec_grade_req);
	string	getName() const;
	bool	getSign();
	int		get_sign_grade_req() const;
	int		get_exec_grade_req() const;

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
};

#endif