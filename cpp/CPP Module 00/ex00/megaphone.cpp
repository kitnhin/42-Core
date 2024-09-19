#include <iostream>

int main(int argc, char *argv[])
{
        if(!argv[1])
                std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
        {
                for(int i = 1; i < argc; i++)
                {
                        for(int j = 0; argv[i][j]; j++)
                                argv[i][j] = std::toupper(argv[i][j]);
                        std::cout << argv[i];
                        if(i < argc - 1)
                                std::cout << ' ';
                }
                std::cout << std::endl;
        }
        return 0;
}