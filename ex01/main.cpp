#include "Span.hpp"

int main( void )
{
    Span span1(6);

    span1.addNumber(3);
    try
    {
        std::cout << span1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    span1.addNumber(8);
    std::cout << span1 << std::endl;
    span1.addNumber(1);
    std::cout << span1 << std::endl;
    span1.addNumber(198);
    std::cout << span1 << std::endl;
    span1.addNumber(25);
    std::cout << span1 << std::endl;
    span1.addNumber(200);
    std::cout << span1 << std::endl;
    try
    {
        span1.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cerr << span1 << std::endl;
    }
    std::cout << span1 << std::endl;

    Span span2(20000);

    std::cout << "Max size of span2 :" << span2.getMaxSize() << " Contains :"
         << span2.getSize() << "numbers" << std::endl;
    span2.randomFill();
    std::cout << span2 << std::endl;

    Span span3(20);
    std::vector<int> tmp;

    tmp.push_back(10);
    tmp.push_back(120);
    tmp.push_back(101);
    tmp.push_back(2);
    span3.addIteratorRange(tmp.begin(), tmp.end());
    std::cout << span3 << std::endl;
}
