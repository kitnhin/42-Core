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
	cout << "\n============ test stack for INT bounds =============\n" << endl;
	MutantStack<int> elaina;
	elaina.push(INT_MAX);
	elaina.push(INT_MIN);
	elaina.push(0);
	MutantStack<int>::const_iterator it4 = elaina.begin();
	MutantStack<int>::const_iterator it4e = elaina.end();
	for(; it4 != it4e; it4++)
		cout << *it4 << endl;
	
	cout << "\n============ test for string stack =============\n" << endl;
	MutantStack<string> miku;
	miku.push("first string");
	miku.push("");
	miku.push("third string (second string pushed is empty)");
	MutantStack<string>::const_iterator it5 = miku.begin();
	MutantStack<string>::const_iterator it5e = miku.end();
	for(; it5 != it5e; it5++)
		cout << *it5 << endl;


	cout << "\n============ test for const stack =============\n" << endl;

	MutantStack<int> cartethyia;
	cartethyia.push(1);
	cartethyia.push(5);
	const MutantStack<int> ciacona = cartethyia;

	MutantStack<int>::const_iterator it3 = ciacona.begin();
	MutantStack<int>::const_iterator it3e = ciacona.end();
	for(; it3 != it3e; ++it3)
		cout << *it3 << endl;
	
	//what if we use a normal iterator to iterate a const stack? 
	// MutantStack<int>::iterator it4 = ciacona.begin();
	// MutantStack<int>::iterator it4e = ciacona.end(); <- does not compile
	// this is because only const functions work for const objects
	// hence since theres no begin() and end() thats const AND returns a normal iterator, it doesnt compile
    
    return 0;
}	//yayyyyy same output i can finally sleep

//btw very nice but begin() gives the bottom of the stack (oldest element)