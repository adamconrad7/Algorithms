This folder contains two .cpp files. The first, generate_data.cpp, writes the denomination base, the number of denominations, and the target amount to make change for to a file called data.txt. The inputs can be changed by editing generate_data.cpp where the comments indicate.

The second file, change.cpp, reads from data.txt from the command line and finds the combination of coins that creates the target amount while using the least amount of coins. It writes its result to a file called change.out, which specifies the denomination of the coin, followed by how many coins of that denomination are present in the solution. Denominations are listed in descending order.

Both .cpp files must be compiled with c++ 11, eg. g++ -std=c++11 change.cpp.
