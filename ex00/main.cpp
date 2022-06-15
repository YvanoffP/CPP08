#include "easyfind.hpp"
#include <vector>
#include <iostream>

template<typename T>
void printIterator( T iterator, T end )
{
    if (iterator != end)
        std::cout << "iterator: " << *iterator << std::endl;
    else
        std::cout << "iterator has reached end of container" << std::endl;
}

int main( void )
{
    std::vector<int> vect;
    std::vector<int>::iterator it;

    for (int i = 1; i < 100; i++)
        vect.push_back(i);
    it = easyfind(vect, 89);
    printIterator(it, vect.end());
    it = easyfind(vect, 200);
    printIterator(it, vect.end());
    it = easyfind(vect, -100);
    printIterator(it, vect.end());

}
