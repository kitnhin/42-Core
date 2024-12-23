#include "MutantStack.hpp"


int main()
{
	cout << endl << "Results from MutantStack: " << endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin(); //basically only these two lines need to code the functions for it haih
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	//first output : top of the stack at first [17]
	//second output: SIZE of the stack after pop (remove top element) [1]
	//third output: the current array stuff after adding and removing

	cout << endl << "Results from list: " << endl;
	std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it2 = mlist.begin();
    std::list<int>::iterator ite2 = mlist.end();

    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::list<int> s2(mlist);
    
    return 0;
}	//yayyyyy same output i can finally sleep