#include "Dog.hpp"
#include "Cat.hpp"

/** ------------------------------------------------------------------
 * NOTE:  ! Use of Virtual
 *  Virtual을 붙인 메소드의 개수 * 4byte만큼 용량이 추가된다.
 * 즉 class마다 v-table이 생성되고, 여기에 함수 포인터(4or8bute)가 추가되는 것이다.
 * -------------------------------------------------------------------*/

int main()
{
	// Test 1
	{
		std::cout << std::endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << std::endl;

		std::cout << std::endl;
		delete j; //should not create a leak
		delete i;
		std::cout << std::endl;
	}


	// Test 2
	{
		std::cout << std::endl;
		Animal *objs[10] = { NULL }; // Uniform initializer. Prevent Down-casting
		std::cout << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				objs[i] = dynamic_cast<Animal *>(new Dog());
			else
				objs[i] = dynamic_cast<Animal *>(new Cat());
		}
		std::cout << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
		{
			objs[i]->makeSound();
		}
		std::cout << std::endl;

		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete objs[i];
		}
		std::cout << std::endl;
	}

	// Test 3 for deep copy
	{
		std::cout << std::endl;
		Dog dog("I will become a super Dog!");
		Dog dog2;
		dog2.makeSound();
		std::cout << "copying memory..." << std::endl;
		dog2 = dog;
		dog2.makeSound();
		dog.changeMemory("Who am i? Where am i?");
		// WARN:  만약 기억을 상실했다면 얕은 복사가 일어난 것.
		dog2.makeSound();
		std::cout << std::endl;
	}

	{
		std::cout << std::endl;
		Cat cat("I will become a cuttest Cat in the world!");
		Cat cat2;
		cat2.makeSound();
		std::cout << "copying memory..." << std::endl;
		cat2 = cat;
		cat2.makeSound();
		cat.changeMemory("Who am i? Where am i?");
		// WARN:  만약 기억을 상실했다면 얕은 복사가 일어난 것.
		cat2.makeSound();
		std::cout << std::endl;
	}


	system("leaks Brain > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");

	//...
	return 0;
}

