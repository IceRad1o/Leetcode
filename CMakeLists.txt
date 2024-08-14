cmake_minimum_required (VERSION 3.8)
project(LeetCode)

add_executable (leetcode LeetCode/leetcode.cpp LeetCode/utility.h
        Algo_DataStructure/Fraction.h)
add_executable (algo Algo_DataStructure/main.cpp
        Algo_DataStructure/main.cpp)