executable: main.o mnist.o utils.o
	g++ -std=c++2a main.o mnist.o utils.o -o executable

main.o: main.cpp
	g++ -std=c++2a -c main.cpp

mnist.o: ./header/datasets.h ./source/mnist.cpp
	g++ -std=c++2a -c ./source/mnist.cpp
	
utils.o: ./header/utils.h ./source/utils.cpp
	g++ -std=c++2a -c ./source/utils.cpp
	
clean:
	rm *.o executable