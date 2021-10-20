./a.out: one.o two.o
	gcc one.o two.o
one.o: one.c server.h
	gcc -c one.c
two.o: two.c
	gcc -c two.c
