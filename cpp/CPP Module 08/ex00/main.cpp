#include "easyfind.hpp"

int main()
{
	//test vector containers
	try
	{
		std::vector<int> vec;
		cout << "vector values: ";
		for(int i = -1; i < 6; i++)
		{
			cout << i << " " ;
			vec.push_back(i);
		}
		cout << endl;
		cout << "Found value: " << *easyfind(vec, 3) << endl;
        cout << "Found value: " << *easyfind(vec, -1) << endl;
		cout << "Found value: " << *easyfind(vec, 7) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	cout << endl;

	//test deque container
	try
	{
		std::deque<int> vec;
		cout << "deque values: ";
		for(int i = -1; i < 6; i++)
		{
			cout << i << " " ;
			vec.push_back(i);
		}
		cout << endl;
		cout << "Found value: " << *easyfind(vec, 3) << endl;
        cout << "Found value: " << *easyfind(vec, -1) << endl;
		cout << "Found value: " << *easyfind(vec, 7) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	cout << endl;

	//test list containers
	try
	{
		std::list<int> vec;
		cout << "list values: ";
		for(int i = -1; i < 6; i++)
		{
			cout << i << " " ;
			vec.push_back(i);
		}
		cout << endl;
		cout << "Found value: " << *easyfind(vec, 3) << endl;
        cout << "Found value: " << *easyfind(vec, -1) << endl;
		cout << "Found value: " << *easyfind(vec, 7) << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	cout << endl;
}

//associative containers are containers that store in order such as set and map