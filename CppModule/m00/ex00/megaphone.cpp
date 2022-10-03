#include <iostream>
#include <cctype> // for toupper()
#include <string> // for std::string

int main(int ac, char **av)
{	
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < ac; i++){
			std::string messege = av[i];
			// NOTE: Both string::size and string::length are synonyms and return the exact same value.
			for (size_t j = 0; j < messege.length(); j++) {
				// NOTE: C-style : std::cout << (char)std::toupper(messege[j]);
				std::cout << static_cast<char>(std::toupper(messege[j]));

				// WARN: toupper는 int형을 반환하기 때문에, char type으로 downcasting애햐 한다.
			}
		}
		std::cout << "\n";
	}
	return (0);
}
