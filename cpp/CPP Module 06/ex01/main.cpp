#include "Serializer.hpp"

int main()
{
	Data *rappa = new Data;
	rappa->str = "walaoeh hen gay ah";

	cout << "Address of data: " << rappa << endl;
	cout << "String inside struct: " << rappa->str << endl;

	uintptr_t mom = Serializer::serialize(rappa);
	cout << "Result of serializer(): " << mom << endl; //numbers wont be the same as the address
//uintptr is the value of the address in unsigned long, ptr is the value in hex

	Data *newptr = Serializer::deserialize(mom);
	cout << "Result of deserializer(): " << newptr << endl;
	cout << "String inside the new ptr: " << newptr->str << endl;

	delete rappa; //sad

	return 0;
}

//english goes out of the window AHHHHHHHHHH
//im not drunk
//as we can see, the hex address is the same, and the value of the string of both pointers r the same