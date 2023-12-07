// Copyright 2017 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/hash2/is_contiguously_hashable.hpp>
#include <boost/core/lightweight_test_trait.hpp>
#include <cstddef>

struct H
{
};

class X;

struct Y
{
};

enum E
{
    v
};

template<class T> void test_true_()
{
    using boost::hash2::is_contiguously_hashable;

    BOOST_TEST_TRAIT_TRUE((is_contiguously_hashable<T, H>));
    BOOST_TEST_TRAIT_TRUE((is_contiguously_hashable<T const, H>));
    BOOST_TEST_TRAIT_TRUE((is_contiguously_hashable<T[2], H>));
    BOOST_TEST_TRAIT_TRUE((is_contiguously_hashable<T const [2], H>));
}

template<class T> void test_false_()
{
    using boost::hash2::is_contiguously_hashable;

    BOOST_TEST_TRAIT_FALSE((is_contiguously_hashable<T, H>));
    BOOST_TEST_TRAIT_FALSE((is_contiguously_hashable<T const, H>));
    BOOST_TEST_TRAIT_FALSE((is_contiguously_hashable<T[2], H>));
    BOOST_TEST_TRAIT_FALSE((is_contiguously_hashable<T const [2], H>));
}

template<class T> void test_true()
{
    test_true_<T>();
    test_true_<T*>();
    test_true_<T[2]>();
    test_true_<T[2][2]>();
}

template<class T> void test_false()
{
    test_false_<T>();
    test_true_<T*>();
    test_false_<T[2]>();
    test_false_<T[2][2]>();
}

int main()
{
    test_true_<bool>();

    test_true_<char>();
    test_true_<signed char>();
    test_true_<unsigned char>();
    test_true_<wchar_t>();
    test_true_<char16_t>();
    test_true_<char32_t>();

    test_true_<short>();
    test_true_<unsigned short>();
    test_true_<int>();
    test_true_<unsigned int>();
    test_true_<long>();
    test_true_<unsigned long>();
    test_true_<unsigned short>();

    test_false_<float>();
    test_false_<double>();
    test_false_<long double>();

    test_false_<std::nullptr_t>();

    test_true_<void*>();
    test_true_<void const*>();

    test_true_<void(*)()>();

    test_true_<E>();

    test_false_<X>();
    test_false_<Y>();

    return boost::report_errors();
}
