#include "MutantStack.hpp"

void display ( MutantStack<int>::iterator it, MutantStack<int> &mstack )
{
	for (MutantStack<int>::iterator it_cpy = it; it_cpy < mstack.end(); it_cpy++) {
		std::cout << *it_cpy << " || ";
	}
	std::cout << std::endl;
}

int main ( void )
{
	MutantStack<int> mstack;

	std::cout << "🚧 === TEST : Push to MutantStack ==== 🚧" << std::endl;
	mstack.push(2);
	mstack.push(5);
	mstack.push(7);
	mstack.push(1);

	std::cout << "### MutantStack ###" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	display(it, mstack);

	std::cout << std::endl;
	std::cout << "Top of Stack : " << mstack.top() << std::endl;
	std::cout << "Size of Stack : " << mstack.size() << std::endl << std::endl;

	std::cout << "### Trying to pop an element ###" << std::endl << std::endl;
	mstack.pop();
	std::cout << "### New MutantStack ###" << std::endl;
	display(it, mstack);
	std::cout << std::endl;

	
	std::cout << "🚧 === TEST : MutantStack Iterator ==== 🚧" << std::endl << std::endl;
	std::cout << "Begin iterator value : " << *it << std::endl;
	std::cout << "### Increment begin iterator ###" << std::endl;
	it++;
	std::cout << "New iterator value : " << *it << std::endl << std::endl;

	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "End iterator value : " << *ite << std::endl;
	ite--;
	std::cout << "### Decrement end iterator ###" << std::endl;
	std::cout << "New iterator value : " << *ite << std::endl;

	return 0;
}
