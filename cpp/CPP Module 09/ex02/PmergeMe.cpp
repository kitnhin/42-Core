#include "PmergeMe.hpp"

unsigned long PmergeMe::num_of_comps = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if(this == &obj)
		return(*this);
	this->vec = obj.vec;
    this->num_of_comps = obj.num_of_comps;
	return(*this);
}

// void    init_vec(vector<int> &nums, int argc, char **argv)
// {
//     for(int i = 1; i < argc; i++)
//     {
//         int n = atoi(argv[i]);
//         nums.push_back(n);
//     }
// }
std::ostream& operator<<(std::ostream& os, const std::pair<int, int>& p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

const char *PmergeMe::InputErrorException::what() const throw()
{
	return("Invalid input detected");
}

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
	cout << "\n" << outputstr << endl << endl;
}

//
//for vec container: 
//


// bool compare_ft(vector<int>::iterator it1, vector<int>::iterator it2)
// {
//     PmergeMe::num_of_comps++;
//     return *it1 < *it2;
// }

int     Jacobsthal(int n)
{
    return ((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}

// void    swap_group(vector<int>::iterator it, vector<int>::iterator ite)
// {
//     std::swap_ranges(it, ite, ite);
// }

// int     biggest_value(vector<int>::iterator it, vector<int>::iterator ite)
// {
//     return *std::max_element(it, ite);
// }

// void    process_element(vector<int>::iterator it, vector<int>::iterator ite)
// {
//     int max1 = biggest_value(it, it + ((ite - it) / 2));
//     int max2 = biggest_value(it + ((ite - it) / 2), ite);

//     //cout << "max1: " << max1 << " max2: " << max2 << endl;
//     PmergeMe::num_of_comps++;
//     if(max2 < max1)
//         swap_group(it,  it + ((ite - it) / 2));
// }


// void    PmergeMe::merge_insertion_sort(int nums_in_element)
// {
//     if(nums_in_element > (int)nums.size() / 2)
//         return ;
    
//     vector<int>::iterator it = nums.begin();
//     int i = 0; //using i cuz way easier to imagine and compare
//     while(i < (int)nums.size() - ((int)nums.size() % nums_in_element))
//     {
//         process_element(it + i, it + i + nums_in_element);
//         i += nums_in_element;
//     }
//     merge_insertion_sort(nums_in_element * 2);

    
//     cout << "\n====================== nums in elements: " << nums_in_element << " ======================\n" << endl;
    
//     cout << "sequence: ";
//     for(int i = 0; i < (int)nums.size(); i++)
//         cout << nums[i] << " ";
//     cout << endl << endl;
//     vector<vector<int>::iterator> main; //iterator vector damn that guide guy is smart asf
//     vector<vector<int>::iterator> pend; //REMEMBER THIS HERE STARTS FROM B2
//     vector<vector<int>::iterator> a;
//     vector<vector<int>::iterator> b;
    
//     int nums_in_group = nums_in_element / 2;
//     // main.push_back(nums.begin() + nums_in_group - 1);
//     // main.push_back(nums.begin() + (2 * nums_in_group) - 1);

//     //int number_of_elements = nums.size() / nums_in_element;
//     int number_of_groups = nums.size() / nums_in_group;

//     // cout << "number of elements: " << number_of_elements << endl;
//     // cout << "number of groups: " << number_of_groups << endl;

//     for(i = 1; i <= number_of_groups; i++)
//     {
//         if(i % 2 == 0)
//             a.push_back(nums.begin() + (i * nums_in_group) - 1);
//         else
//             b.push_back(nums.begin() + (i * nums_in_group) - 1);
//     }

//     cout << "a: ";
//     for(i = 0; i < (int)a.size(); i++)
//         cout << *a[i] << " ";
//     cout << endl;

//     cout << "b: ";
//     for(i = 0; i < (int)b.size(); i++)
//         cout << *b[i] << " ";
//     cout << endl;

//     main.push_back(b[0]);
//     for(i = 0; i < (int)a.size(); i++)
//         main.push_back(a[i]);
//     for(i = 1; i < (int)b.size(); i++)
//         pend.push_back(b[i]);

//     vector<int>::iterator elements_left = nums.begin() + number_of_groups * nums_in_group;

//     cout << "\nmain: " << endl;
//     for(i = 0; i < (int)main.size(); i++)
//     {
//         vector<int>::iterator it = main[i];
//         //cout << "value at iterator: |" << *main[i] << "| ";
//         for(int j = -nums_in_group + 1; j <= 0; j++)
//             cout << *(it + j) << " ";
//     }
//     cout << endl;

//     cout << "\npend: " << endl;
//     for(i = 0; i < (int)pend.size(); i++)
//     {
//         vector<int>::iterator it = pend[i];
//         //cout << "value at iterator: |" << *pend[i] << "| ";
//         for(int j = -nums_in_group + 1; j <= 0; j++)
//             cout << *(it + j) << " ";
//     }
//     cout << endl;


//     a.erase(a.begin()); // remove a1
//     int n = 2;
//     while(pend.size())
//     {
//         int curr_J = Jacobsthal(n);
//         int prev_J = Jacobsthal(n - 1);
//         int diff = curr_J - prev_J;
//         if(diff < (int)pend.size())
//         {
//             for(i = diff - 1; i >= 0; i--)
//             {
//                 vector<vector<int>::iterator>::iterator upper_bound_limit = std::find(main.begin(), main.end(), a[i]);
//                 vector<vector<int>::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
//                 cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |" << *(*upper_bound_limit) << endl;
//                 main.insert(pos, pend[i]);
//                 pend.erase(pend.begin() + i);
//                 a.erase(a.begin() + i);
//             }
//         }
//         else
//         {
//             for(int i = (int)pend.size() - 1; i >= 0; i--)
//             {
//                 vector<vector<int>::iterator>::iterator upper_bound_limit;
//                 if((int)a.size() > i)
//                 {
//                     // cout << "a_value: " << *a[i] << endl;
//                     upper_bound_limit = std::find(main.begin(), main.end(), a[i]);
//                 }
//                 else
//                 {
//                     // cout << "a_value: " << *a[i] << endl;
//                     upper_bound_limit = main.end();
//                 }

//                 vector<vector<int>::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
//                 if(upper_bound_limit != main.end())
//                     cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |" << *(*upper_bound_limit) << endl;
//                 else
//                     cout << "\ninserting b value: |" << *pend[i] << "| upper bound used: |end" << endl;
//                 main.insert(pos, pend[i]);

//                 pend.erase(pend.begin() + i);
//                 if((int)a.size() > i)
//                     a.erase(a.begin() + i);
//             }
//         }
//         n++;
//     }

//     // for(int i = pend.size() - 1; i >= 0; i--)
//     // {
//     //     vector<vector<int>::iterator>::iterator upper_bound_limit = std::find(main.begin(), main.end(), a[i + 1]); // note: careful this isnt protected MIGHT SEG FAULT LOLLLL
//     //     vector<vector<int>::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
//     //     main.insert(pos, pend[i]);
//     // }

//     vector<int> res;
//     for(i = 0; i < (int)main.size(); i++)
//     {
//         vector<int>::iterator it = main[i];
//         for(int j = -nums_in_group + 1; j <= 0; j++)
//             res.push_back(*(it + j));
//     }

//     for(; elements_left != nums.end(); elements_left++)
//         res.push_back(*elements_left);

//     nums = res;

//     cout << "\nnums after sort: " << endl;
//     for(i = 0; i < (int)nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
//     cout << endl;
// }

vector<int>     &PmergeMe::getVec()
{
    return this->vec;
}

list<int>       &PmergeMe::getList()
{
    return this->lst;
}

unsigned long maximum_comparisons(int n)
{
    unsigned long sum = 0;
    for(int k = 1; k <= n; k++)
    {
        double value = (3.0/4.0) * k;
        sum += static_cast<unsigned long>(ceil(log2(value)));
    }
    return sum;
}

double  calculate_time(struct timeval start, struct timeval end)
{
    double seconds = end.tv_sec - start.tv_sec;
    double microsecs = end.tv_usec - start.tv_usec;
    return seconds * 1e6 + microsecs;
}
