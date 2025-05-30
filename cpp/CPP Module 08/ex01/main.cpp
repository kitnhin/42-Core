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
	cout << endl << "=========== own tests: =========" << endl;
	cout << "\nvalid tests:" << endl;
	Span test1 = Span(4);
	test1.addNumber(5);
	test1.addNumber(100);
	test1.addNumber(2);
	test1.addNumber(-200);
	cout << "Numbers: ";
	for(size_t i = 0; i < test1.getContainer().size(); i++)
		cout << test1.getContainer()[i] << " ";
	cout << endl;
	cout << "longest span: " << test1.longestSpan() << endl;
	cout << "shortest span: " << test1.shortestSpan() << endl;

	//the INT boundaries
	Span test5(4);
	test5.addNumber(INT_MAX);
	test5.addNumber(INT_MIN);
	test5.addNumber(2);
	cout << "\nINT bounds test:" << endl;
	cout << "Numbers: ";
	for(size_t i = 0; i < test5.getContainer().size(); i++)
		cout << test5.getContainer()[i] << " ";
	cout << endl;
	cout << "longest span: " << test5.longestSpan() << endl;
	cout << "shortest span: " << test5.shortestSpan() << endl;
	
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


	//test alot of nums
	cout << "\n++++++++++++++ ALOT NUMS ++++++++++++++++\n" << endl;
	try
	{
		cout << "test alot nums:" << endl;
		int size = 200;
		int count = 10;
		Span test3(size);

		test3.add_multiple_nums(1, 200, count);
		cout << "numbers: ";
		for(size_t i = 0; i < test3.getContainer().size(); i++)
			cout << test3.getContainer()[i] << " ";
		cout << endl;
		cout << "longest span: " << test3.longestSpan() << endl;
		cout << "shortest span: " << test3.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span test4(5);
		cout << "\ntest invalid range:" << endl;
		test4.add_multiple_nums(5, 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span test5(5);
		cout << "\ntest invalid count:" << endl;
		test5.add_multiple_nums(5, 10, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//test alot nums USING ITERATORS

	cout << "\n++++++++++++++ ALOT NUMS using iterators ++++++++++++++\n" << endl;
	try
	{
		cout << "test alot nums:" << endl;
		int size = 200;
		int count = 10;
		Span test6(size);

		test6.add_multiple_nums(1, 20, count);
		cout << "numbers (first container): ";
		for(size_t i = 0; i < test6.getContainer().size(); i++)
			cout << test6.getContainer()[i] << " ";
		cout << endl;
		
		Span test7(20);
		test7.addNumber(5);
		test7.addNumber(2);
		test7.iterator_add_multiple_nums(test6.getContainer().begin(), test6.getContainer().end());
		cout << "numbers (second container): ";
		for(size_t i = 0; i < test7.getContainer().size(); i++)
			cout << test7.getContainer()[i] << " ";
		cout << endl;

		cout << "longest span: " << test7.longestSpan() << endl;
		cout << "shortest span: " << test7.shortestSpan() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span test8(5);
		cout << "\ntest invalid iterators:" << endl;
		test8.addNumber(1);
		Span test9(5);
		test9.iterator_add_multiple_nums(test8.getContainer().end(), test8.getContainer().begin());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span test8(5);
		cout << "\ntest invalid range:" << endl;
		test8.addNumber(1);
		test8.addNumber(2);
		Span test9(1);
		test9.iterator_add_multiple_nums(test8.getContainer().begin(), test8.getContainer().end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}