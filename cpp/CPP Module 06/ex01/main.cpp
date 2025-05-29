#include "Serializer.hpp"

int main()
{
	Data *rappa = new Data;
	rappa->str = "walaoeh";

	cout << "Address of data: " << rappa << endl;
	cout << "String inside struct: " << rappa->str << endl;

	uintptr_t mom = Serializer::serialize(rappa);
	cout << "Result of serializer(): " << mom << endl; //numbers wont be the same as the address
//uintptr is the value of the address in unsigned long, ptr is the value in hex

	Data *newptr = Serializer::deserialize(mom);
	cout << "Result of deserializer(): " << newptr << endl;
	cout << "String inside the new ptr: " << newptr->str << endl;

	delete rappa; //sad

	//null test
	cout << endl;
	Data *castorice = NULL;
	uintptr_t herta = Serializer::serialize(castorice);
	cout << "Result of serializer(): " << herta << endl;

	Data *newptr2 = Serializer::deserialize(herta);
	cout << "Result of deserializer(): " << newptr2 << endl;

	return 0;
}

//english goes out of the window AHHHHHHHHHH
//im not drunk
//as we can see, the hex address is the same, and the value of the string of both pointers r the same


//types of casts:
//static cast (general use)
//dynamic cast (polymorphism)
//const cast (const -> normal or vv)
//reinterprate cast (forcefully cast unrelated types), generally avoid unless necc cuz no validity checks

//in this case, dynamic cast is used cuz we wanna convert "pointer" data type to "numbers" data type