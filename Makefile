test_lib: test_array_lib.o array_sort_lib.o Makefile
		gcc -ansi -Wall -g test_array_lib.o array_sort_lib.o -o test_lib

test_array_lib.o: test_array_lib.c array_sort_lib.h Makefile
	gcc -ansi -Wall -O -c test_array_lib.c

array_sort_lib.o: array_sort_lib.c Makefile
	gcc -ansi -Wall -O -c array_sort_lib.c

pulisci:
	rm -f *.o

pulisci_tutto:
	rm -f test_array_lib test_lib *.o 
	

