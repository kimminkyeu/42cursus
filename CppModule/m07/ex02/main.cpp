#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "[Test 1]\n";
    std::cout << "----------------------------------\n";
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        std::cout << "\n";
        Array<int> tmp = numbers;
        std::cout << "tmp:  " << tmp[0] << "  \tnumbers: " << numbers[0] << "\n";
        std::cout << "tmp:  " << tmp[1] << "  \tnumbers: " << numbers[1] << "\n";
        std::cout << "tmp:  " << tmp[2] << "  \tnumbers: " << numbers[2] << "\n";
        Array<int> test(tmp);
        std::cout << "\n";
        std::cout << "test:  " << tmp[0] << "  \ttmp: " << numbers[0] << "\n";
        std::cout << "test:  " << tmp[1] << "  \ttmp: " << numbers[1] << "\n";
        std::cout << "test:  " << tmp[2] << "  \ttmp: " << numbers[2] << "\n";
        std::cout << "\n";
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1; // NOTE:  If error, then close program
        }
    }
    std::cout << "\nOK\n\n";
    std::cout << "[Test 2]\n";
    std::cout << "----------------------------------\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "\n";
    delete [] mirror;//
    return 0;
}
