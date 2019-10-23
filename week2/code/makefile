proj:main.o fun1.o fun2.o mysort.o syssort.o
	gcc main.o fun1.o fun2.o mysort.c syssort.c -o proj
main.o:main.c
	gcc -c main.c
fun1.o:fun1.c
	gcc -c fun1.c
fun2.o:fun2.c
	gcc -c fun2.c
mysort.o:mysort.c
	gcc -c mysort.c
syssort.o:syssort.c
	gcc -c syssort.c
clean:
	rm -f *.o

