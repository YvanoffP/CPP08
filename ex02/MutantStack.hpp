#ifndef MUTANT_STACK_H
# define MUTANT_STACK_H

#include <iostream>
#include <stack>

template< typename T >
class MutantStack: public std::stack<T> {

	public:
		MutantStack<T> ( void ): std::stack<T>() {}
		MutantStack<T> ( const MutantStack &copy ): std::stack<T>(copy) {}
		~MutantStack<T> ( void ) {}

		MutantStack<T> &operator=( const MutantStack &right ) {
			if (&right != this)
				*this = right;
			return (*this);
		}

		// Had to call it iterator because of subjet
		// If we name it "it" for example, the subject main can't compile 
		// because of : MutantStack<int>::iterator it = mstack.begin() line

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin ( void ) { return (std::stack<T>::c.begin()); }
		iterator end ( void ) {	return (std::stack<T>::c.end()); }

		const_iterator begin ( void ) const { return (std::stack<T>::c.begin()); }
		const_iterator end ( void ) const { return (std::stack<T>::c.end()); }
};

#endif
