#include <algorithm>

template<typename T>
typename T::iterator easyfind( T &container, int to_find )
{
    typename T::iterator result = find(container.begin(), container.end(), to_find);

    if (result == container.end())
        return container.end();
    return result;
}
