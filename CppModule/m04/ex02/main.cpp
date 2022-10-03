#include "Rabbit.hpp"

int main()
{
	/*
	부모 함수에 Virtual을 붙여도, 상속받은 자식의 헤더에 그 함수를 정의하지 않았다면 문제 없음.
	*/

	// AAnimal animal;
	// animal.makeSound();
	// std::cout << animal.getType() << std::endl;

	Rabbit rabbit;
	rabbit.makeSound();
	std::cout << rabbit.getType() << std::endl;



	return 0;
}

