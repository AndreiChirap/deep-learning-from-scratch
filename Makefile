exec: main.o MNIST.o
	g++ -std=c++2a main.o MNIST.o -o exec

main.o: main.cpp
	g++ -std=c++2a -c main.cpp

MNIST.o: ./header/MNIST.h ./source/MNIST.cpp
	g++ -std=c++2a -c ./source/MNIST.cpp
	
clean:
	rm *.o exec