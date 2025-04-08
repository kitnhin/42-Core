#include "Brain.hpp"

Brain::Brain()
{
	cout << "Brain default constructor called" << endl;
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
}

Brain::~Brain()
{
	cout << "Brain destroyed" << endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	cout << "Brain copy assignment operator called" << endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}

void Brain::setidea(string idea, int n)
{
	this->ideas[n] = idea;
}

string Brain::getidea(int n)
{
	if(this->ideas[n] == "")
		cout << "no idea at this brain slot" << endl;
	return(this->ideas[n]);
}