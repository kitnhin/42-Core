#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int replacewords(string buffer, char **argv)
{
	string outfile_name = (string)argv[1] + ".replace";
	string ori_word = (string)argv[2];
	string new_word = (string)argv[3];

	ofstream outfile(outfile_name);
	if(!outfile.is_open())
	{
		cout << "failed to open outfile rip" << endl;
		return 1;
	}
	for(int i = 0; buffer[i] != '\0'; i++)
	{
		int pos = buffer.find(ori_word, i); //find postion of next word that we wanna replace
		if(i == pos)
		{
			outfile << new_word;
			i += string(ori_word).length() - 1;
		}
		else
			outfile << buffer[i];
	}
	return 0;
}
int main(int argc, char **argv)
{
	char temp;
	string buffer;
	if(argc != 4)
	{
		cout << "dont try to be funny use the correct syntax" << endl;
		return 1;
	}
	ifstream infile(argv[1]); //constructor can help open
	if(!infile.is_open())
	{
		cout << "infile cant be opened" << endl;
		return 1;
	}
	while (infile >> std::noskipws >>temp)
		buffer += temp;
	buffer += '\0';
	infile.close();
	if (replacewords(buffer, argv))
		return 1; 
	return 0;
}