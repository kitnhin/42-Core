#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>
#include <string>

using std::stack;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class RPN
{
	private:
		stack<int> nums;

	public:
		RPN();
		RPN(const RPN &obj);
		~RPN();
		RPN &operator=(const RPN &obj);

		int	exec_op(int a, int b, char op);
		void	execute_RPN(string input);
};

#endif