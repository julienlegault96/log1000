
Vector: Vector.o main.o
	g++ -o Vector main.o Vector.o

Vector.o: Vector.cpp Vector.h
	g++ -o Vector.o -c Vector.cpp

main.o : main.cpp Vector.h
	g++ -o main.o -c main.cpp

clean : main.o Vector.o Vector
	rm Vector
	rm *.o