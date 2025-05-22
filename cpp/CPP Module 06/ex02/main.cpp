#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "Functions.hpp"

int main()
{
	Base *kaboom = generate();
	identify(kaboom);
	identify((*kaboom));
	delete kaboom;
	return 0;
}

//just keep running it lol

//dynamic cast literally build for this exercise
//dynamic casting is to class from base class to derived class (Base -> A or Animal -> cat or smth)
//if the object created isnt the object we wanna cast to:
//	Base *test = new A;
//	B *newptr = dynamic_cast<B*>;
//it will return a NULL ptr, so we can see like if the cast doesnt return NULL then we know the derived class dy
//for reference same concept but it will throw exception instead of NULL ptr, hence the try catches