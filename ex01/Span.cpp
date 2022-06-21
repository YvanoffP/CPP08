#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <cstdlib>

// CONSTRUCTORS / DESTRUCTORS

Span::Span( void ): _storedSize(0)
{
    return ;
}

Span::Span( unsigned int n ): _storedSize(n), _vect(0)
{
    return ;
}

Span::~Span( void )
{
    return ;
}

// GETTERS

unsigned int Span::getSize( void ) const
{
    return _vect.size();
}

unsigned int Span::getMaxSize( void ) const
{
    return _storedSize;
}

// Operator

Span & Span::operator=( Span const & rhs )
{
    if (this == &rhs)
        return *this;
    this->_storedSize = rhs._storedSize;
    this->_vect = rhs._vect;
    return *this;
}

std::ostream &operator<<( std::ostream &ostr, const Span &instance )
{
    int shortest = instance.shortestSpan();
    int longest = instance.longestSpan();

    ostr << "Span of max size " << instance.getMaxSize() << " contains "
        << instance.getSize() << " numbers, shortest span is "
        << shortest << " and longest is " << longest;
    return ostr;
}

// MEMBER FUNCTIONS

void Span::addNumber( int num )
{
    if (_vect.size() == _storedSize)
        throw std::out_of_range("Cannot add any more numbers");
    _vect.push_back(num);
}

void Span::addIteratorRange( std::vector<int>::iterator begin,
        std::vector<int>::iterator end)
{
    std::vector<int> tmp(begin, end);

    if (tmp.size() > this->spaceLeft())
        throw std::out_of_range("addIteratorRange cannot add more numbers");
    copy(tmp.begin(), tmp.end(), std::back_inserter(this->_vect));
}

void Span::randomFill( void )
{
    unsigned int space_left = this->spaceLeft();

    for (unsigned int i = 0; i < space_left; i++)
        this->addNumber(rand() % (this->getMaxSize() * 50));
}

int Span::shortestSpan( void ) const
{
    std::vector<int>            tmp = _vect;
    int                         result = -1;
    std::vector<int>::iterator  iterator;

    if (_vect.size() <= 1)
        throw std::logic_error("Not enough numbers stored for a shortest span");
    sort(tmp.begin(), tmp.end());
    result = *(tmp.begin() + 1) - *tmp.begin();
    if (this->getSize() == 2)
        return result;
    for (iterator = tmp.begin() + 1; iterator != tmp.end() - 1 && result != 0; iterator++)
    {
        if (*(iterator + 1) - *iterator < result)
            result = *(iterator + 1) - *iterator;
    }
    return result;
}

int Span::longestSpan( void ) const
{
    std::vector<int> tmp = _vect;

    if (_vect.size() <= 1)
        throw std::logic_error("Not enough numbers stored for a longest span");
    sort(tmp.begin(), tmp.end());
    return *(tmp.end() - 1) - *tmp.begin();
}

unsigned int Span::spaceLeft( void ) const
{
    return getMaxSize() - getSize();
}
