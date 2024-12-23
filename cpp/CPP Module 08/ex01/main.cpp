#include "Span.hpp"

int main()
{
	//main from subject
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	//own tests
	cout << endl << "own tests: " << endl;
	Span test1 = Span(10001);
	for(int i = 0; i < 10000; i++)
		test1.addNumber(i);
	test1.addNumber(20000);
	std::cout << "shortest span: " << test1.shortestSpan() << std::endl; //1
	std::cout << "longest span: " << test1.longestSpan() << std::endl; // 20000 last element added minus first

	//test exceptions
	cout << endl << "test exceptions:" << endl;
	try
	{
		test1.addNumber(1);
	}
	catch(const std::exception& e) // limit reached exception caught
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Span test2(1);
		test2.addNumber(1);
		test2.longestSpan();
	}
	catch(const std::exception& e) // no span exception caught
	{
		std::cerr << e.what() << endl;
	}
	return 0;
}