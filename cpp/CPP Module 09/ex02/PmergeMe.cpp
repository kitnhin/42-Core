#include "PmergeMe.hpp"

void	print_and_filter_unsorted_list(int argc, char **argv)
{
	string outputstr = "Unsorted array:";
	for(int i = 1; i < argc; i++)
	{
		string temp = static_cast<string>(argv[i]);
		if(temp.find_first_not_of("0123456789") != string::npos) //i need to find more functions like these wtf so useful
			throw PmergeMe::InputErrorException();
		else
			outputstr += " " + temp;
	}
	cout << outputstr << endl;
}

//
//for vec container: 
//


vector<pair<int, int> > mergePairs_vec(vector<pair<int, int> > left_vec, vector<pair<int, int> > right_vec)
{
    vector<pair<int, int> >::iterator iterator_left = left_vec.begin();
    vector<pair<int, int> >::iterator iterator_right = right_vec.begin();
    vector<pair<int, int> > res_vec;

    while(iterator_left != left_vec.end() && iterator_right != right_vec.end())
    {
        if((*iterator_left).second < (*iterator_right).second) // compare the bigger numbers
        {
            res_vec.push_back(*iterator_left);
            iterator_left++;
        }
        else
        {
            res_vec.push_back(*iterator_right);
            iterator_right++;
        }
    }
    // push the remaining stuff
    while(iterator_left != left_vec.end())
    {
        res_vec.push_back(*iterator_left);
        iterator_left++;
    }
    while(iterator_right != right_vec.end())
    {
        res_vec.push_back(*iterator_right);
        iterator_right++;
    }
    return res_vec;
}

vector<pair<int, int> > mergeSort_vec(vector<pair<int, int> > pairs_vec)
{
    if(pairs_vec.size() == 1)
        return pairs_vec;

    vector<pair<int, int> > left_vec(pairs_vec.begin(), pairs_vec.begin() + pairs_vec.size() / 2);
    vector<pair<int, int> > right_vec(pairs_vec.begin() + pairs_vec.size() / 2, pairs_vec.end());

    left_vec = mergeSort_vec(left_vec);
    right_vec = mergeSort_vec(right_vec);

    return mergePairs_vec(left_vec, right_vec); //basically splitting everything then arranging back, like merge sort
}

vector<pair<int, int> > formPairs_vec(int argc, char **argv)
{
    vector<pair<int, int> > pairs_vec;
    int firstnum = -1;
    int secnum = -1;

    //iterating and doing stuff one at a time trying out new coding style
    for(int i = 1; i < argc; i++)
    {
        string temp = static_cast<string>(argv[i]);
        if(firstnum == -1)
            firstnum = stoi(temp);
        else
        {
            secnum = stoi(temp);
            if(firstnum < secnum)
                pairs_vec.push_back(std::make_pair(firstnum, secnum)); //first num will be the smaller one in the pair
            else
                pairs_vec.push_back(std::make_pair(secnum, firstnum));
            firstnum = -1; //reset
        }
    }
    return pairs_vec;
}

vector<int> push_larger_array_vec(vector<pair<int, int> > pairs_vec)
{
    vector<int> res_vec;

    for(vector<pair<int, int> >::iterator it = pairs_vec.begin(); it != pairs_vec.end(); it++)
        res_vec.push_back((*it).second);
    return res_vec;
}

vector<int> insert_other_nums_vec(vector<int> sorted_vec, vector<pair<int, int> > pairs_vec, int odd)
{
    for(vector<pair<int, int> >::iterator it = pairs_vec.begin(); it != pairs_vec.end(); it++)
    {
        vector<int>::iterator pos = lower_bound(sorted_vec.begin(), sorted_vec.end(), (*it).first);
        sorted_vec.insert(pos, (*it).first);
    }
    if(odd != -1)
    {
        vector<int>::iterator pos = lower_bound(sorted_vec.begin(), sorted_vec.end(), odd);
        sorted_vec.insert(pos, odd);
    }
    return sorted_vec;
}

void PmergeMe::sort_vec(int argc, char **argv)
{
    vector<pair<int, int> > pairs_vec;

	std::chrono::time_point<std::chrono::system_clock> starttime_vec = std::chrono::system_clock::now();

    pairs_vec = formPairs_vec(argc, argv);
    pairs_vec = mergeSort_vec(pairs_vec);
    this->sorted_vec = push_larger_array_vec(pairs_vec);

    if(argc % 2 == 0) //take into account the odd number that isn't in a pair
        this->sorted_vec = insert_other_nums_vec(sorted_vec, pairs_vec, stoi(static_cast<string>(argv[argc - 1])));
    else
        this->sorted_vec = insert_other_nums_vec(sorted_vec, pairs_vec, -1);
	
	std::chrono::time_point<std::chrono::system_clock> endtime_vec = std::chrono::system_clock::now();
	std::chrono::microseconds duration_vec = std::chrono::duration_cast<std::chrono::microseconds>(endtime_vec - starttime_vec);

	cout << "After:";
	for(vector<int>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); it++)
		cout << " " << *it;
	cout << endl; 
	cout << "Time to process a range of " << argc - 1 << "elements with std::vector: " << duration_vec.count() << "us" << endl;
}


//
//for deque: (cuz stupid list doesnt have lowerbound acc to gpt)
//

deque<pair<int, int> > mergePairs_deque(deque<pair<int, int> > left_deque, deque<pair<int, int> > right_deque)
{
    deque<pair<int, int> >::iterator iterator_left = left_deque.begin();
    deque<pair<int, int> >::iterator iterator_right = right_deque.begin();
    deque<pair<int, int> > res_deque;

    while (iterator_left != left_deque.end() && iterator_right != right_deque.end())
    {
        if ((*iterator_left).second < (*iterator_right).second) // compare the bigger numbers
        {
            res_deque.push_back(*iterator_left);
            iterator_left++;
        }
        else
        {
            res_deque.push_back(*iterator_right);
            iterator_right++;
        }
    }
    // push the remaining stuff
    while (iterator_left != left_deque.end())
    {
        res_deque.push_back(*iterator_left);
        iterator_left++;
    }
    while (iterator_right != right_deque.end())
    {
        res_deque.push_back(*iterator_right);
        iterator_right++;
    }
    return res_deque;
}

deque<pair<int, int> > mergeSort_deque(deque<pair<int, int> > pairs_deque)
{
    if (pairs_deque.size() == 1)
        return pairs_deque;

    deque<pair<int, int> > left_deque(pairs_deque.begin(), pairs_deque.begin() + pairs_deque.size() / 2);
    deque<pair<int, int> > right_deque(pairs_deque.begin() + pairs_deque.size() / 2, pairs_deque.end());

    left_deque = mergeSort_deque(left_deque);
    right_deque = mergeSort_deque(right_deque);

    return mergePairs_deque(left_deque, right_deque); //basically splitting everything then arranging back, like merge sort
}

deque<pair<int, int> > formPairs_deque(int argc, char **argv)
{
    deque<pair<int, int> > pairs_deque;
    int firstnum = -1;
    int secnum = -1;

    //iterating and doing stuff one at a time
    for (int i = 1; i < argc; i++)
    {
        string temp = static_cast<string>(argv[i]);
        if (firstnum == -1)
            firstnum = stoi(temp);
        else
        {
            secnum = stoi(temp);
            if (firstnum < secnum)
                pairs_deque.push_back(std::make_pair(firstnum, secnum)); //first num will be the smaller one in the pair
            else
                pairs_deque.push_back(std::make_pair(secnum, firstnum));
            firstnum = -1;// reset
        }
    }
    return pairs_deque;
}

deque<int> push_larger_array_deque(deque<pair<int, int> > pairs_deque)
{
    deque<int> res_deque;

    for (deque<pair<int, int> >::iterator it = pairs_deque.begin(); it != pairs_deque.end(); it++)
        res_deque.push_back((*it).second);
    return res_deque;
}

deque<int> insert_other_nums_deque(deque<int> sorted_deque, deque<pair<int, int> > pairs_deque, int odd)
{
    for (deque<pair<int, int> >::iterator it = pairs_deque.begin(); it != pairs_deque.end(); it++)
    {
        deque<int>::iterator pos = lower_bound(sorted_deque.begin(), sorted_deque.end(), (*it).first);
        sorted_deque.insert(pos, (*it).first);
    }
    if (odd != -1)
    {
        deque<int>::iterator pos = lower_bound(sorted_deque.begin(), sorted_deque.end(), odd);
        sorted_deque.insert(pos, odd);
    }
    return sorted_deque;
}

void PmergeMe::sort_deque(int argc, char **argv)
{
    deque<pair<int, int> > pairs_deque;

	std::chrono::time_point<std::chrono::system_clock> starttime_deque = std::chrono::system_clock::now();

    pairs_deque = formPairs_deque(argc, argv);
    pairs_deque = mergeSort_deque(pairs_deque);
    this->sorted_deque = push_larger_array_deque(pairs_deque);

    if (argc % 2 == 0) //take into account the odd number that isn't in a pair
        this->sorted_deque = insert_other_nums_deque(sorted_deque, pairs_deque, stoi(static_cast<string>(argv[argc - 1])));
    else
        this->sorted_deque = insert_other_nums_deque(sorted_deque, pairs_deque, -1);

	std::chrono::time_point<std::chrono::system_clock> endtime_deque = std::chrono::system_clock::now();
	std::chrono::microseconds duration_deque = std::chrono::duration_cast<std::chrono::microseconds>(endtime_deque - starttime_deque);
	cout << "Time to process a range of " << argc - 1 << "elements with std::deque: " << duration_deque.count() << "us" << endl; // .count extracts the value out
}


