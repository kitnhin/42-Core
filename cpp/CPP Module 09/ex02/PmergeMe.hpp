#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <cmath>
#include <ctime>
#include <sys/time.h>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::pair;
using std::list;
using std::deque;


class PmergeMe
{
	private:
		vector<int> vec;
		list<int>	lst;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &obj);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &obj);

		void    merge_insertion_sort(int nums_in_element);
		vector<int>	&getVec();
		list<int>	&getList();

		class InputErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		
		static unsigned long num_of_comps;
};



//other fts
void	print_and_filter_unsorted_list(int argc, char **argv);
std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p);
unsigned long maximum_comparisons(int n);

double	calculate_time(struct timeval start, struct timeval end);
int     Jacobsthal(int n);
bool 	compare_ft(vector<int>::iterator it1, vector<int>::iterator it2);


//template fts

template <typename Container>
void    init_arr(Container &nums, int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        int n = atoi(argv[i]);
        nums.push_back(n);
    }
}

template <typename Container>
void    swap_group(typename Container::iterator it, typename Container::iterator ite)
{
    std::swap_ranges(it, ite, ite);
}

template <typename Container>
int     biggest_value(typename Container::iterator it, typename Container::iterator ite)
{
    return *std::max_element(it, ite);
}

template <typename Container>
void    process_element(typename Container::iterator it, typename Container::iterator ite)
{
	//get middle iterator
	typename Container::iterator mid = it;
	std::advance(mid, std::distance(it, ite) / 2);

    int max1 = biggest_value<Container>(it, mid);
    int max2 = biggest_value<Container>(mid, ite);

    //cout << "max1: " << max1 << " max2: " << max2 << endl;
    PmergeMe::num_of_comps++;
    if(max2 < max1)
        swap_group<Container>(it,  it + ((ite - it) / 2));
}

//main ft
template<typename Container>
void    merge_insertion_sort(Container &nums, int nums_in_element)
{
	if(nums_in_element > (int)nums.size() / 2)
        return ;
    
    typename Container::iterator it = nums.begin();
    int i = 0; //using i cuz way easier to imagine and compare
    while(i < (int)nums.size() - ((int)nums.size() % nums_in_element))
    {
        process_element<Container>(it + i, it + i + nums_in_element);
        i += nums_in_element;
    }
    merge_insertion_sort(nums, nums_in_element * 2);

    
    cout << "\n====================== nums in elements: " << nums_in_element << " ======================\n" << endl;
    
    cout << "sequence: ";
    for(int i = 0; i < (int)nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl << endl;

    vector<typename Container::iterator> main; //iterator vector damn that guide guy is smart asf
    vector<typename Container::iterator> pend; //REMEMBER THIS HERE STARTS FROM B2
    vector<typename Container::iterator> a;
    vector<typename Container::iterator> b;
    
    int nums_in_group = nums_in_element / 2;
    // main.push_back(nums.begin() + nums_in_group - 1);
    // main.push_back(nums.begin() + (2 * nums_in_group) - 1);

    //int number_of_elements = nums.size() / nums_in_element;
    int number_of_groups = nums.size() / nums_in_group;

    // cout << "number of elements: " << number_of_elements << endl;
    // cout << "number of groups: " << number_of_groups << endl;

    for(i = 1; i <= number_of_groups; i++)
    {
        if(i % 2 == 0)
            a.push_back(nums.begin() + (i * nums_in_group) - 1);
        else
            b.push_back(nums.begin() + (i * nums_in_group) - 1);
    }

    cout << "a: ";
    for(i = 0; i < (int)a.size(); i++)
        cout << *a[i] << " ";
    cout << endl;

    cout << "b: ";
    for(i = 0; i < (int)b.size(); i++)
        cout << *b[i] << " ";
    cout << endl;

    main.push_back(b[0]);
    for(i = 0; i < (int)a.size(); i++)
        main.push_back(a[i]);
    for(i = 1; i < (int)b.size(); i++)
        pend.push_back(b[i]);

    vector<int>::iterator elements_left = nums.begin() + number_of_groups * nums_in_group;

    cout << "\nmain: " << endl;
    for(i = 0; i < (int)main.size(); i++)
    {
        typename Container::iterator it = main[i];
        //cout << "value at iterator: |" << *main[i] << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
            cout << *(it + j) << " ";
    }
    cout << endl;

    cout << "\npend: " << endl;
    for(i = 0; i < (int)pend.size(); i++)
    {
        typename Container::iterator it = pend[i];
        //cout << "value at iterator: |" << *pend[i] << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
            cout << *(it + j) << " ";
    }
    cout << endl;


    a.erase(a.begin()); // remove a1
    int n = 2;
    while(pend.size())
    {
        int curr_J = Jacobsthal(n);
        int prev_J = Jacobsthal(n - 1);
        int diff = curr_J - prev_J;
        if(diff < (int)pend.size())
        {
            for(i = diff - 1; i >= 0; i--)
            {
                typename vector<typename Container::iterator>::iterator upper_bound_limit = std::find(main.begin(), main.end(), a[i]);
                typename vector<typename Container::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
                cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |" << *(*upper_bound_limit) << endl;
                main.insert(pos, pend[i]);
                pend.erase(pend.begin() + i);
                a.erase(a.begin() + i);
            }
        }
        else
        {
            for(int i = (int)pend.size() - 1; i >= 0; i--)
            {
                typename vector<typename Container::iterator>::iterator upper_bound_limit;
                if((int)a.size() > i)
                    upper_bound_limit = std::find(main.begin(), main.end(), a[i]);
                else
                    upper_bound_limit = main.end();

                typename vector<typename Container::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
                if(upper_bound_limit != main.end())
                    cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |" << *(*upper_bound_limit) << endl;
                else
                    cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |end" << endl;
                main.insert(pos, pend[i]);

                pend.erase(pend.begin() + i);
                if((int)a.size() > i)
                    a.erase(a.begin() + i);
            }
        }
        n++;
    }

    // for(int i = pend.size() - 1; i >= 0; i--)
    // {
    //     vector<vector<int>::iterator>::iterator upper_bound_limit = std::find(main.begin(), main.end(), a[i + 1]); // note: careful this isnt protected MIGHT SEG FAULT LOLLLL
    //     vector<vector<int>::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
    //     main.insert(pos, pend[i]);
    // }

    vector<int> res;
    for(i = 0; i < (int)main.size(); i++)
    {
        vector<int>::iterator it = main[i];
        for(int j = -nums_in_group + 1; j <= 0; j++)
            res.push_back(*(it + j));
    }

    for(; elements_left != nums.end(); elements_left++)
        res.push_back(*elements_left);

    nums = res;

    cout << "\nnums after sort: " << endl;
    for(i = 0; i < (int)nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << endl;
}

#endif