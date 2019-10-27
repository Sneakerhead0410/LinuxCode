proj:main.o oprmode.o oprfile.o
	gcc main.o oprmode.o oprfile.c -o proj
main.o:main.c
	gcc -c main.c
oprmode.o:oprmode.c
	gcc -c oprmode.c
oprfile.o:oprfile.c
	gcc -c oprfile.c
clean:
	rm -f *.o
