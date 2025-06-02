#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include "Array.hpp"

int main(int, char**)
{
	//check if functioning properly
    Array<int> numbers(5);
    int* mirror = new int[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        const int value = rand() % 10;
        numbers[i] = value;
        mirror[i] = value;
    }
	cout << "Array results: ";
	for(int i = 0; i < 5; i++)
		cout << numbers[i];
	cout << endl;
	cout << "Mirror results: ";
	for(int i = 0; i < 5; i++)
		cout << mirror[i];
	cout << endl;
	delete [] mirror;

	//try funny exceptions
	cout << "Test []: " << endl;
	try
	{
		Array<int> temp1(5);
		int yes = temp1[6];
		cout << "index in range " << endl;
	}
	catch(const std::exception& e) // exception caught if index too high
	{
		std::cerr << e.what() << endl;
	}
	try
	{
		Array<int> temp2(5);
		int no = temp2[-1];
		(void)no;
	}
	catch(const std::exception& e) // exception caught if index too low
	{
		std::cerr << e.what() << endl;
	}
	cout << endl;

	//time to test copy and assignment haih
	cout << "before assignment operator: " << endl;
	cout << "temp3 arr: ";
	Array<int>temp3(5);
	for(int i = 0; i < 4; i++)
	{
		temp3[i] = i;
		cout << temp3[i] << " ";
	}
	cout << endl;
	cout << "temp3 size: " << temp3.getSize() << endl;

	cout << "temp4 arr: ";
	Array<int>temp4(2);
	for(int i = 0; i < 2; i++)
	{
		temp4[i] = i;
		cout << temp4[i] << " ";
	}
	cout << endl;
	cout << "temp4 size: " << temp4.getSize() << endl;
	cout << endl;

	cout << "After assignment operator: " << endl;
	cout << "temp3 arr: ";
	temp4 = temp3;
	for(int i = 0; i < 4; i++)
		cout << temp3[i] << " ";
	cout << endl;
	cout << "temp3 size: " << temp3.getSize() << endl;

	cout << "temp4 arr: ";
	for(int i = 0; i < 4; i++)
		cout << temp4[i] << " ";
	cout << endl;
	cout << "temp4 size: " << temp3.getSize() << endl;

	//now we see if we change something in one array does it change the other
	
	temp4.increment_value(0); // increment the first number of temp4
	cout << endl;
	cout << "test change value: " << endl;
	cout << "temp3 arr: ";
	for(int i = 0; i < 4; i++)
		cout << temp3[i] << " ";
	cout << endl;
	cout << "temp3 size: " << temp3.getSize() << endl;

	cout << "temp4 arr: ";
	for(int i = 0; i < 4; i++)
		cout << temp4[i] << " ";
	cout << endl;
	cout << "temp4 size: " << temp3.getSize() << endl; // temp3 doesnt change

	//string test
	cout << "\n ===== Test for std::string: ====\n" << endl;

    Array<string> str_arr(2);
	str_arr[0] = "IDW TO LOSE 5050 PLS IM BROKE";
	str_arr[1] = "CARTETHYIA PLS COME HOMEEEE";

	Array<string> str_arr_mirror = str_arr;

	cout << "\nBefore changes: " << endl;
	cout << "Original array: " << endl;
	cout << "string1: " << str_arr[0] << endl;
	cout << "string2: " << str_arr[1] << endl;
	cout << "Mirror array: " << endl;
	cout << "string1: " << str_arr_mirror[0] << endl;
	cout << "string2: " << str_arr_mirror[1] << endl;

	str_arr[0] = "100 pulls and a dream :sob:";
	cout << "\nAfter changes: " << endl;
	cout << "Original array: " << endl;
	cout << "string1: " << str_arr[0] << endl;
	cout << "string2: " << str_arr[1] << endl;
	cout << "Mirror array: " << endl;
	cout << "string1: " << str_arr_mirror[0] << endl;
	cout << "string2: " << str_arr_mirror[1] << endl;

	//struct test
	cout << "\n ===== Test for struct: ====\n" << endl;

    Array<test*> struct_arr(2);
	struct_arr[0] = new test();
	struct_arr[1] = new test();

	Array<test*> struct_arr_mirror = struct_arr;

	cout << "\nBefore changes: " << endl;
	cout << "Original array: " << endl;
	cout << "ptr1: " << struct_arr[0] << endl;
	cout << "ptr2: " << struct_arr[1] << endl;
	cout << "Mirror array: " << endl;
	cout << "ptr1: " << struct_arr_mirror[0] << endl;
	cout << "ptr2: " << struct_arr_mirror[1] << endl;

	delete struct_arr[0];
	struct_arr[0] = NULL;
	cout << "\nAfter changes: " << endl;
	cout << "Original array: " << endl;
	cout << "ptr1: " << struct_arr[0] << endl;
	cout << "ptr2: " << struct_arr[1] << endl;
	cout << "Mirror array: " << endl;
	cout << "ptr1: " << struct_arr_mirror[0] << endl;
	cout << "ptr2: " << struct_arr_mirror[1] << endl;

	delete struct_arr[1];
    return 0;
}


// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
// 		Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
	
//     for (int i = 0; i < MAX_VAL; i++)
//     {
// 		if (mirror[i] != numbers[i])
//         {
// 			std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }