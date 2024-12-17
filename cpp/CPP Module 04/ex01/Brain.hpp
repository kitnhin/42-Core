#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	private:
	string ideas[100];

	public:
	string	getidea(int n);
	void	setidea(string idea, int n);

	Brain();
	Brain(const Brain &obj);
	~Brain();
	Brain &operator=(const Brain &obj);
};

#endif
