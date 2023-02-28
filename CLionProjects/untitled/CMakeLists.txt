cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp CostumerQueue.cpp CashierQueue.cpp cmp.cpp CostumerNode.cpp CashierNode.cpp BaristaNode.cpp BaristaQueue.cpp SecondVersion.cpp FirstVersion.cpp cmpforid.cpp)
