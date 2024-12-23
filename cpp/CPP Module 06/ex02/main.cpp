#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include "Functions.hpp"

int main()
{
	Base *kaboom = generate();
	identify(kaboom);
	identify(&(*kaboom));
	delete kaboom;
	return 0;
}
//just keep running it lol
