#include "MutantStack.hpp"
#include <list>

int main()
{
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << std::endl;
	l.pop_back();
	std::cout << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}	

	return 0;
}
