#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <chrono>
#include <deque>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::pair;
using std::list;
using std::deque;


bool compare_ft(vector<int>::iterator it1, vector<int>::iterator it2)
{
    return *it1 < *it2;
}

int     Jacobsthal(int n)
{
    return ((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}

void    swap_group(vector<int>::iterator it, vector<int>::iterator ite)
{
    std::swap_ranges(it, ite, ite);
}

int     biggest_value(vector<int>::iterator it, vector<int>::iterator ite)
{
    return *std::max_element(it, ite);
}

void    process_element(vector<int>::iterator it, vector<int>::iterator ite)
{
    int max1 = biggest_value(it, it + ((ite - it) / 2));
    int max2 = biggest_value(it + ((ite - it) / 2), ite);

    //cout << "max1: " << max1 << " max2: " << max2 << endl;
    if(max2 < max1)
        swap_group(it,  it + ((ite - it) / 2));
}
void    merge_insertion_sort(vector<int> &nums, int nums_in_element)
{
    if(nums_in_element > nums.size() / 2)
        return ;
    
    vector<int>::iterator it = nums.begin();
    int i = 0; //using i cuz way easier to imagine and compare
    while(i < nums.size() - (nums.size() % nums_in_element))
    {
        process_element(it + i, it + i + nums_in_element);
        i += nums_in_element;
    }
    merge_insertion_sort(nums, nums_in_element * 2);


    // cout << "nums after merge: ";
    // for(int i = 0; i < nums.size(); i++)
    //     cout << nums[i] << " ";
    // cout << endl;
    
    cout << "\n====================== nums in elements: " << nums_in_element << " ======================\n" << endl;
    vector<vector<int>::iterator> main; //iterator vector damn that guide guy is smart asf
    vector<vector<int>::iterator> pend; //REMEMBER THIS HERE STARTS FROM B2
    vector<vector<int>::iterator> a;
    vector<vector<int>::iterator> b;
    
    int nums_in_group = nums_in_element / 2;
    // main.push_back(nums.begin() + nums_in_group - 1);
    // main.push_back(nums.begin() + (2 * nums_in_group) - 1);

    int number_of_elements = nums.size() / nums_in_element;
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
    for(i = 0; i < a.size(); i++)
        cout << *a[i] << " ";
    cout << endl;

    cout << "b: ";
    for(i = 0; i < b.size(); i++)
        cout << *b[i] << " ";
    cout << endl;

    main.push_back(b[0]);
    for(i = 0; i < a.size(); i++)
        main.push_back(a[i]);
    for(i = 1; i < b.size(); i++)
        pend.push_back(b[i]);

    // for(i = 3; i <= number_of_groups; i++)
    // {
    //     if(i % 2 == 1)
    //         pend.push_back(nums.begin() + (i * nums_in_group) - 1);
    //     else
    //         main.push_back(nums.begin() + (i * nums_in_group) - 1);
    // }

    vector<int>::iterator elements_left = nums.begin() + number_of_groups * nums_in_group;

    cout << "\nmain: " << endl;
    for(i = 0; i < main.size(); i++)
    {
        vector<int>::iterator it = main[i];
        //cout << "value at iterator: |" << *main[i] << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
            cout << *(it + j) << " ";
    }
    cout << endl;

    cout << "\npend: " << endl;
    for(i = 0; i < pend.size(); i++)
    {
        vector<int>::iterator it = pend[i];
        //cout << "value at iterator: |" << *pend[i] << "| ";
        for(int j = -nums_in_group + 1; j <= 0; j++)
            cout << *(it + j) << " ";
    }
    cout << endl;


    for(int i = pend.size() - 1; i >= 0; i--)
    {
        vector<vector<int>::iterator>::iterator upper_bound_limit = std::find(main.begin(), main.end(), a[i + 1]); // note: careful this isnt protected MIGHT SEG FAULT LOLLLL
        vector<vector<int>::iterator>::iterator pos = std::upper_bound(main.begin(), upper_bound_limit, pend[i], compare_ft);
        main.insert(pos, pend[i]);
    }

    vector<int> res;
    for(i = 0; i < main.size(); i++)
    {
        vector<int>::iterator it = main[i];
        for(int j = -nums_in_group + 1; j <= 0; j++)
            res.push_back(*(it + j));
    }

    for(; elements_left != nums.end(); elements_left++)
        res.push_back(*elements_left);

    nums = res;

    cout << "\nnums after sort: " << endl;
    for(i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << endl;

    // vector<int> main;
    // vector<int> pend;
    
    // int nums_in_group = nums_in_element / 2;
    // main.insert(main.end(), nums.begin(), nums.begin() + nums_in_group);
    // main.insert(main.end(), nums.begin() + nums_in_group, nums.begin() + (2 * nums_in_group));

    // int number_of_elements = nums.size() / nums_in_element;
    // int number_of_groups = nums.size() / nums_in_group;

    // cout << "number of elements: " << number_of_elements << endl;
    // cout << "number of groups: " << number_of_groups << endl;

    // for(i = 2; i < number_of_groups; i++)
    // {
    //     if(i % 2 == 0)
    //         pend.insert(pend.end(), nums.begin() + (i * nums_in_group), nums.begin() + ((i + 1) * nums_in_group));
    //     else
    //         main.insert(main.end(), nums.begin() + (i * nums_in_group), nums.begin() + ((i + 1) * nums_in_group));
    // }

    // cout << "\nmain: " << endl;
    // for(i = 0; i < main.size(); i++)
    //     cout << main[i] << " ";
    // cout << endl;

    // cout << "\npend: " << endl;
    // for(i = 0; i < pend.size(); i++)
    //     cout << pend[i] << " ";
    // cout << endl;
}

int main()
{
    int arr[] = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    vector<int> vec(std::begin(arr), std::end(arr));
    //swap_group(vec.begin(), vec.begin() + 2);
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    
    cout << endl;
    merge_insertion_sort(vec, 2);
    cout << "sorted: ";
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    // for(int i = 0; i < 8; i++)
    //     cout << Jacobsthal(i) << endl;

    // int arr[] = {0, 1, 3, 4, 7};
    // vector<int> vec(std::begin(arr), std::end(arr));
    // insert_num(vec, 8, vec.begin(), vec.end());
    // for(int i = 0; i < vec.size(); i++)
    //     cout << vec[i] << " ";
    // cout << endl;
}