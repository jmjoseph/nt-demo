// test_modifiers.cpp
#include "../src/modifiers.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include <vector>
#include <numeric>


TEST_CASE( "Initial test values") 
{
    std::vector<int> vals(30);
    std::iota(std::begin(vals), std::end(vals), 1);
    int threshold = 5;
    std::vector<int> mult = {5, 10, 15, 20, 25, 30};
    REQUIRE( get_multiples(vals, threshold) == mult );
}

TEST_CASE( "Short test" ) 
{
    std::vector<int> vals = {5, 6, 7, 8, 9, 10};
    int threshold = 5;
    std::vector<int> mult = {5, 10};
    REQUIRE( get_multiples(vals, threshold) == mult );
    
    vals.push_back(11);
    REQUIRE( get_multiples(vals, threshold) == mult );
}


TEST_CASE( "Test for num_ints = threshold" ) 
{
    std::vector<int> vals(20);
    std::iota(std::begin(vals), std::end(vals), 1);
    int threshold = 20;
    std::vector<int> mult = {20};
    REQUIRE( get_multiples(vals, threshold) == mult );
}
