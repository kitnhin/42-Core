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
using std::advance;


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
bool compare_ft(typename Container::iterator it1, typename Container::iterator it2)
{
    PmergeMe::num_of_comps++;
	//cout << "comparing : |" << *it1 << "| and |" << *it2 << "|" << endl;  
    return *it1 < *it2;
}

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
        swap_group<Container>(it,  mid);
}

//main ft
template<typename Container>
void    merge_insertion_sort(Container &nums, int nums_in_element)
{
	if(nums_in_element > (int)nums.size())
        return ;
    
	unsigned long curr_comp = PmergeMe::num_of_comps;
    typename Container::iterator it = nums.begin();
    int i = 0; //using i cuz way easier to imagine and compare
    while(i < (int)nums.size() - ((int)nums.size() % nums_in_element))
    {
		typename Container::iterator elem_start = it;
		typename Container::iterator elem_end = it;

		advance(elem_start, i);
		advance(elem_end, i + nums_in_element);
        process_element<Container>(elem_start, elem_end);
        i += nums_in_element;
    }

	cout << "curr comp when nums in element = " << nums_in_element << " is |" << PmergeMe::num_of_comps - curr_comp << endl;
    merge_insertion_sort(nums, nums_in_element * 2);
    
    cout << "\n====================== nums in elements: " << nums_in_element << " ======================\n" << endl;
    
	curr_comp = PmergeMe::num_of_comps;
    cout << "sequence: ";
    for(typename Container::iterator print_i = nums.begin(); print_i != nums.end(); print_i++)
        cout << *print_i << " ";
    cout << endl << endl;

    vector<typename Container::iterator> main; //iterator vector damn that guide guy is smart asf
    vector<typename Container::iterator> pend; //REMEMBER THIS HERE STARTS FROM B2
    vector<typename Container::iterator> a;
    vector<typename Container::iterator> b;
    
    int nums_in_group = nums_in_element / 2;
    int number_of_groups = nums.size() / nums_in_group;

    for(i = 1; i <= number_of_groups; i++)
    {
		typename Container::iterator temp = nums.begin();
		advance(temp, (i * nums_in_group) - 1);
        if(i % 2 == 0)
            a.push_back(temp);
        else
            b.push_back(temp);
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
	{
        pend.push_back(b[i]);
	}

	// cout << "sequence: ";
    // for(typename Container::iterator print_i = nums.begin(); print_i != nums.end(); print_i++)
    //     cout << *print_i << " ";
    // cout << endl << endl;

	cout << endl;
    typename Container::iterator elements_left = nums.begin();
	advance(elements_left, number_of_groups * nums_in_group);

    cout << "main: " << endl;
    for(i = 0; i < (int)main.size(); i++)
    {
        typename Container::iterator pos = main[i];
		advance(pos, -nums_in_group + 1);
        //cout << "value at iterator: |" << *pos << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
			cout << *(pos++) << " ";
    }
    cout << endl;

    cout << "\npend: " << endl;
    for(i = 0; i < (int)pend.size(); i++)
    {
        typename Container::iterator pos = pend[i];
		advance(pos, -nums_in_group + 1);
        //cout << "value at iterator: |" << *pend[i] << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
			cout << *(pos++) << " "; 
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
                typename vector<typename Container::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft<Container>);
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

                typename vector<typename Container::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft<Container>);
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
	// 	typename vector<typename Container::iterator>::iterator upper_bound_limit;
	// 	if((int)a.size() > i)
    //     	upper_bound_limit = std::find(main.begin(), main.end(), a[i]);
    //     else
    //     	upper_bound_limit = main.end();
    //     typename vector<typename Container::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft<Container>);
    //     main.insert(pos, pend[i]);
	// 	pend.erase(pend.begin() + i);
    // 	if((int)a.size() > i)
    //         a.erase(a.begin() + i);
    // }

    cout << endl;

    Container res;
    for(i = 0; i < (int)main.size(); i++)
    {
        typename Container::iterator pos = main[i];
		advance(pos, -nums_in_group + 1);
        for(int j = -nums_in_group + 1; j <= 0; j++)
            res.push_back(*(pos++));
    }

    for(; elements_left != nums.end(); elements_left++)
        res.push_back(*elements_left);

    nums = res;

    cout << "\nnums after sort: " << endl;
    for(typename Container::iterator print_i = nums.begin(); print_i != nums.end(); print_i++)
        cout << *print_i << " ";
    cout << endl;
    cout << endl;
	cout << "num of comparisons = " << PmergeMe::num_of_comps - curr_comp << endl;
}

#endif