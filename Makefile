exec: main.o datasets.o utils.o
	g++ -std=c++2a main.o datasets.o utils.o -o exec

main.o: main.cpp
	g++ -std=c++2a -c main.cpp

datasets.o: ./header/datasets.h ./source/datasets.cpp
	g++ -std=c++2a -c ./source/datasets.cpp
	
utils.o: ./header/utils.h ./source/utils.cpp
	g++ -std=c++2a -c ./source/utils.cpp
	
clean:
	rm *.o exec