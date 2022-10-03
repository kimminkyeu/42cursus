#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// NOTE:  (1). 포인터를 이용하지 않고, 타입이 각 class에 맞는 경우.
	std::cout << "[Case1]" << std::endl;
	Animal animal;
	std::cout << "Size of class: " << sizeof(animal) << std::endl;
	animal.makeSound();
	std::cout << animal.getType() << "\n";

	std::cout << std::endl;
	Dog dog;
	std::cout << "Size of class: " << sizeof(animal) << std::endl;
	dog.makeSound();
	std::cout << dog.getType() << "\n";

	std::cout << std::endl;
	Cat cat;
	std::cout << "Size of class: " << sizeof(animal) << std::endl;
	std::cout << std::endl;
	cat.makeSound();
	std::cout << cat.getType(); // uses Animal::getType()
	std::cout << std::endl;

	// NOTE:  (2). 포인터가 타입을 잘 가리키고 있다면 문제 없음.
	std::cout << std::endl;
	std::cout << "[Case2]" << std::endl;
	Cat *cat_ptr = &cat;
	std::cout << cat_ptr->getType() << "\n"; // uses Animal::getType()
	cat_ptr->makeSound();
	std::cout << std::endl;

	// NOTE:  (3). 포인터가 다른 타입을 가질 경우.
	std::cout << std::endl;
	std::cout << "[Case3 : typeCasting to Base Class (Animal)]" << std::endl;
	dynamic_cast<Animal*>(cat_ptr)->makeSound(); /** WARN:  calling Animal::makeSound() */
	std::cout << std::endl;
	cat_ptr->Cat::makeSound();
	cat_ptr->Animal::makeSound();


	std::cout << cat_ptr->getType() << "\n";
	std::cout << std::endl;


	// NOTE:  (3). 포인터로 부모를 가르키고, 타입이 부모가 될 경우. (배열에 자식들 담기 가능)
	std::cout << std::endl;
	std::cout << "[Case4 : Mandatory Case]" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();


	// WARN:  delete functions calls Animal::~Animal(), not ~Dog() nor ~Cat()
	// this may case memory-leak if it's member has own allocated memory (Ex. array data member)
	delete j;
	delete i;
	delete meta;
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
