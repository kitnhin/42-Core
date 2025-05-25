#include <iostream>
#include <cstdlib>
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
	try
	{
		Array<int> temp1(5);
		int yes = temp1[6];
		(void)yes;
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