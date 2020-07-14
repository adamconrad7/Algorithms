This folder contains two files. The first, generate_data.cpp, creates an n * 2 list of integers, the first column corresponding to an item's weight and the second the item's benefit (or value). The first row is the number of items (n).
The number of items can be changed by changing the value of n in the program, as indicated by the comments.

The second file, knapsack.cpp reads in the data.txt file and outputs the optimal value attainable with a given weight. The weight value is hardcoded, and can be changed where the comments indicate.

The programs must be compiled with g++ -std=c++11. data.txt must be provided to knapsack.cpp as a command line argument.
