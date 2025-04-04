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

	ofstream outfile;
	outfile.open(outfile_name.c_str());
	if(!outfile.is_open())
	{
		cout << "failed to open outfile rip" << endl;
		return 1;
	}
	size_t pos = 0;
	string temp;
	while((pos = buffer.find(ori_word, pos)) != string::npos)
	{
		temp = new_word + buffer.substr(pos + ori_word.length(), buffer.length() - (pos + ori_word.length()));
		buffer = buffer.substr(0, pos);
		buffer += temp;	
		pos += new_word.length();
	}
	outfile << buffer;
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
	if(buffer == "")
	{
		infile.close();
		cout << "File is empty" << endl;
		return 0;
	}
	infile.close();
	if (replacewords(buffer, argv))
		return 1; 
	return 0;
}