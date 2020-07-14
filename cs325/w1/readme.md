This file contains three c++ programs. The first, generate_data.cpp, generates a .txt file of random numbers 0-10000 (exclusive) called data.txt. The first entry is the number of random numbers generated. The other two programs, insetionsort.cpp and mergesort.cpp use this data.txt file as supplied from the command line. Each program sorts the provided list five times, outputs the sorted list in insert.out or merge.out, respectively. The programs then measures the time it takes to sort the list each iteration, and outputs each sorting runtime as well as the average runtime into the file times.out

In order to run the sorting programs, they must be compiled with the C++11 standard, done by providing the -std=c++11 argument when compiling.

Different input sizes were obtained by changing the value of n in generate_data.cpp, then recording running times for each algorithm before again changing the input size. 
