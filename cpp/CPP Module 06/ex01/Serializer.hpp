#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

using std::string;
using std::cout;
using std::endl;

typedef struct Data
{
	string str; // non emptry struct yes
}	Data;

//i sincerely apologies to my evaluator all my codes ive been doin after schul which is kinda depressing

class Serializer
{
	private:
	Serializer();

	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	Serializer(const Serializer &obj);
	~Serializer();
	Serializer &operator=(const Serializer &obj);
};

#endif