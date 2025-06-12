#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &obj)
{
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
	if(this == &obj)
		return (*this);
	this->nums = obj.nums;
	return(*this);
}

int	RPN::exec_op(int a, int b, char op)
{
	switch(op)
	{
		case('+'):
			return(a + b);
		case('-'):
			return(a - b);
		case('*'):
			return(a * b);
		case('/'):
			if (b == 0)
				throw std::logic_error("Error: cannot divide by 0");
			return(a / b);
	}
	return(0);
}

void	RPN::execute_RPN(string input)
{
	for(int i = 0; i < (int)input.length(); i++)
	{
		if(input[i] == ' ')
			continue ;
		else if(isdigit(input[i]))
		{
			if((i - 1 >= 0 && isdigit(input[i - 1])) || (i + 1 < (int)input.length() && isdigit(input[i + 1])))
				throw std::logic_error("Error: only single digits nums pls");
			nums.push(static_cast<int>(input[i] - '0'));
		}
		else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if(input[i] == '-' && i + 1 < (int)input.length() && isdigit(input[i + 1]))
			{
				nums.push(std::atoi(input.substr(i, 2).c_str()));
				i++;
				continue;
			}
			if(nums.size() < 2)
				throw std::logic_error("Error: not enough numbers");
			int b = nums.top();
			nums.pop();
			int a = nums.top();
			nums.pop();
			nums.push(exec_op(a,b,input[i]));
		}
		else
			throw std::logic_error("Error: unknown char detected");
	}
	if(nums.size() != 1)
		throw std::logic_error("Error: either got more than one num left or no numbers left (calculation error)");
	cout << nums.top() << endl;
}

//wahsai very very nice one of the easiest exercises in so long
//basically push numbers on stack, when see operator, take the top two numbers and exec the op, then push the result back on stack and repeat
//e.g. 7 7 * 7 -
//step1: push7
//step2: push7
//step3: see * operator, take top 2 elements(7 and 7) and multiply, return result(49) on top of stack
//step4: push7
//step5: see - operator, take top 2 elements(49 and 7) and minus, return result(42) on top of stack
//step6: if nth wrong there's always gonna be the result left only so just print it