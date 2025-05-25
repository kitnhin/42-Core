#include "iter.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


void	increment_by_one(char &c)
{
	c++;
}

void	appendstr(string &str)
{
	str.append(" is very gay. ");
}

void	increment_by_one_int(int &i)
{
	i++;
}

void	gacha(string &str) //inspired by justyns gacha during eval lol
{	
	srand(time(0));
	if(rand() % 30 == 1) // increased the chances cuz wtf is my luck
		str.append("woahhhhh 5* char wooooooo!!!! (cant say the same in actual gacha tho)");
	else if(rand() % 10 == 3)
		str.append("u got a 4* weap");
	else if(rand() % 10 == 1)
		str.append("u got a 4* char");
	else if(rand() % 2 == 0)
		str.append("unlucky 3* weap rip");
	else
		str.append("unlucky 3* char rip");
	usleep(700000);
	cout << str << endl;
}
//wtf ive been playing this for almost half an hour and still no 5* huhhhhhhh

int main()
{
	char arr[] = "012345";
	iter(arr, 6, increment_by_one);
	for(int i = 0; i < 6; i++)
		cout << arr[i];
	cout << endl;

	string arr2[] = {"justyn" , "joshua", "yikeat"};
	iter(arr2, 3, appendstr);
	for(int i = 0; i < 3; i++)
		cout << arr2[i];
	cout << endl;

	cout << '\n' << "generating gacha pull..." << endl; // 10 pulls cuz no gems :/
	string arr4[] = {"pull1: ", "pull2: ", "pull3: ", "pull4: ", "pull5: ", "pull6: ", "pull7: ", "pull8: ", "pull9: ", "pull10: "};
	iter(arr4, 10, gacha);
}