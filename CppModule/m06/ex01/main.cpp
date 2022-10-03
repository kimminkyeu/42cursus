#include <iostream>
#include <string>

struct Data
{
	int i;
};

/**
 *  NOTE:  uintptr_t / intptr_t : 포인터(주소)의 정수표현에 유용 + (max size of pointer cast)
 * ----------------------------------------------------------------------------------
 * A common reason to want an integer type that can hold an architecture's pointer type
 * is to perform integer-specific operations on a pointer, or to obscure
 * the type of a pointer by providing it as an integer "handle".
 */

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data*>(ptr));
}

int main(int ac, char **av)
{
	Data data;
	data.i = 42;

	Data* data_ptr = &data;

	uintptr_t t1 = serialize(data_ptr);
	Data* t2 = deserialize(t1);

	std::cout << "uintptr_t : " << t1 << "\n";
	std::cout << "Data*     : " << t2 << "\n";
	std::cout << ((size_t)t1 == (size_t)t2 ? "same" : "different") << "\n";
	// 같은 값이지만, 주소 출력되는 진법이 달라진다.


	return (0);
}
