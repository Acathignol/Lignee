
all: main

main:	main.o Individual.o Environment.o Life.o
	g++ -g main.o  Individual.o Environment.o Life.o -o main 

main.o: main.cpp Individual.o Environment.o Life.o
	g++ -c main.cpp -o main.o --std=c++11 -g

Individual.o: Individual.cpp Individual.h
	g++ -c Individual.cpp -Wall -Wextra -o Individual.o --std=c++11 -g

Environment.o: Environment.cpp Environment.h
	g++ -c Environment.cpp -Wall -Wextra -o Environment.o --std=c++11 -g
	
Life.o: Life.cpp Life.h
	g++ -c Life.cpp -Wall -Wextra -o Life.o --std=c++11 -g

clean:
	rm -f *.o
