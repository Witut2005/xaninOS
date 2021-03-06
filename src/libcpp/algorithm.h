
#pragma once
#include <stdint.h>
#include <libcpp/utility.h>

namespace std
{


template<class input_type, class f_type>
f_type for_each(input_type begin, input_type end, f_type function )
{

    for(input_type i = begin; i != end; i++)
    {
       function(*i); 
    }

    return function;

}


template<class T>
constexpr T& max(T& x, T& y)
{
    return (x > y) ? x : y; 
}

template<class T>
constexpr T& min(T& x, T& y)
{
    return (x < y) ? x : y; 
}

template<class T>
constexpr T min_element(T x, T y)
{
    auto min = x;
    
    for(auto a = x; a != y; a++)
    {
        if(*a <= *min)
            min = a;
    }
    
    return min;

}

template<class T>
constexpr T max_element(T x, T y)
{
    auto max = x;
    
    for(auto a = x; a != y; a++)
    {
        if(*a >= *max)
            max = a;
    }
    
    return max;
}

template<class T, class X>
constexpr bool equal(const T*  beg, const T*  end, const X*  beg2)
{
        
    for(const T* x = beg; x != end; x++, beg2++)
    {
        if(*x != *beg2)
            return false;
    }

    return true;

}


template<class T> 
constexpr void swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}


template <class T>
T* find(const T* beg, const T* end, const T value)
{

    for(; beg != end; beg++)
    {
        if(*beg == value)
            return const_cast<T*> (beg);
    }

    
    return const_cast<T*> (end);

}

template<class T>
constexpr std::pair<T&&, T&&> minmax(T&& a, T&& b)
{
    if (a < b) return std::pair<T&&, T&&>(a, b);
    else return std::pair<T&&, T&&>(a, b);
}



}
