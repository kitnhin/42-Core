#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

int replace_str(char **argv, string buffer)
{
	ofstream outfile;
	outfile.open(string(argv[1]) + ".replace");
	if(outfile.is_open())
	{
		for(int i = 0; buffer[i] != '\0' ; i++)
		{
			int pos = buffer.find(argv[2], i);
			if(pos == i)
			{
				outfile << argv[3];
				i += string(argv[2]).size() - 1; // need -1 if not will skip the next char
				// tried without the -1 and without the else below, will have weird behavior when the substr is at the EOF
			}
			else
				outfile << buffer[i];
		}
		return 0;
	}
	else
	{
		cout << "Error cannnot open outfile: " << string(argv[1]) << ".replace";
		return 1;
	}
}
int main(int argc, char **argv)
{
	string buffer;
	char c;
	if(argc != 4)
	{
		cout << "Dont try to be funny, syntax : <filename> <s1> <s2>" << endl;
		return 1;
	}
	ifstream infile;
	infile.open(argv[1]);
	if(infile.is_open())
	{
		while(infile >> std::noskipws >> c)
			buffer += c;
		buffer += '\0';
		infile.close();
		if (replace_str(argv, buffer) == 1)
			return 1;
		return 0;
	}
	else
	{
		cout << "unable to open file" << endl;
		return 1;
	}
}