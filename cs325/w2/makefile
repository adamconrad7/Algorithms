CC=gcc --std=c++11 -g

# all: test_dynarray test_list
#
# test_dynarray: test_dynarray.c test_data.h dynarray.o
# 	$(CC) test_dynarray.c dynarray.o -o test_dynarray
#
# test_list: test_list.c test_data.h list.o
# 	$(CC) test_list.c list.o -o test_list
#
# dynarray.o: dynarray.c dynarray.h
# 	$(CC) -c dynarray.c
#
# list.o: list.c list.h
# 	$(CC) -c list.c
#

all: test

test: main.o badsort.h badsort.o
		$(CC) main.cpp badsort.o -o test

main.o: main.cpp
	$(CC) -c main.cpp

badsort.o: badsort.cpp badsort.h
		$(CC) -c badsort.cpp

clean:
	 rm -f dynarray.o list.o test_dynarray test_list
