#include "Functions.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base *generate(void)
{
	srand(time(0));
	int n = rand() % 3;

	//to ensure my ans is correct
	if(n == 0)
		cout << "Object created is object A" << endl;
	else if(n == 1)
		cout << "Object created is object B" << endl;
	else
		cout << "Object created is object C" << endl;

	//creating objects
	if(n == 0)
		return(new A);
	else if(n == 1)
		return(new B);
	else
		return(new C);
}

void identify(Base* p)
{
	cout << "result of identify(*p): object ";
	if(dynamic_cast<A*>(p))
		cout << "A";
	else if(dynamic_cast<B*>(p))
		cout << "B";
	else if(dynamic_cast<C*>(p))
		cout << "C";
	else
		cout << "ERROR OOPSSSS";
	cout << endl;
}


void identify(Base& p)
{
	try
	{
		A &a_ref = dynamic_cast<A&>(p);
		cout << "result of identify (&p): object A" << endl;
		(void)a_ref; // the funny unused variable again (guess where i got this from AHAHAHHA)
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b_ref = dynamic_cast<B&>(p);
			cout << "result of identify (&p): object B" << endl;
			(void)b_ref;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c_ref = dynamic_cast<C&>(p);
				cout << "result of identify (&p): object C" << endl;
				(void)c_ref;
			}
			catch(const std::exception& e)
			{
				std::cerr << "wtf how..." << endl;
			}
		}
	}
}

//dynamic cast carrying this exercise fr its build for this