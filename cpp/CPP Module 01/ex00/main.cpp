#include "Zombie.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
	Zombie *BrainEater = newZombie("BrainEater");
	BrainEater->announce(); // <- this BrainEater zombie is stored in the heap, so need new to make (malloc)
	randomChump("UrMom"); // <- this UrMom zombie is stored in the stack, therefore when the function returns it is automatically destroyed.
	delete BrainEater; //<- since BrainEater is created by new (malloc), have to del to prevent mem leaks (free)
	return (0);
}