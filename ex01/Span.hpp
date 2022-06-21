#ifndef SPAN_H
#define SPAN_H

# include <vector>
# include <iostream>

class Span
{

public:
    Span( void );
    Span( unsigned int n );
    Span( const Span &src );
    ~Span( void );

    Span &operator=( const Span &rhs );
    void addNumber( int num );

    int shortestSpan( void ) const;
    int longestSpan( void ) const;

    unsigned int getSize( void ) const;
    unsigned int getMaxSize( void ) const;
    unsigned int spaceLeft( void ) const;
    void addIteratorRange( std::vector<int>::iterator begin,
            std::vector<int>::iterator end );
    void randomFill( void );

private:

    unsigned int _storedSize;
    std::vector<int> _vect;

};

std::ostream &operator<<( std::ostream &ostr, const Span &instance );

#endif
