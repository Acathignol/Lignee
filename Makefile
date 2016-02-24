
all: main

main:	main.o Individual.o Environment.o Life.o Image.o Crowd.o
	g++ -g main.o  Individual.o Environment.o Life.o Image.o Crowd.o -o main 

main.o: main.cpp Individual.o Environment.o Life.o Image.o Crowd.o
	g++ -c main.cpp -o main.o --std=c++11 -g

Individual.o: Individual.cpp Individual.h
	g++ -c Individual.cpp -Wall -Wextra -o Individual.o --std=c++11 -g

Crowd.o: Crowd.cpp Crowd.h
	g++ -c Crowd.cpp -Wall -Wextra -o Crowd.o --std=c++11 -g
	
Environment.o: Environment.cpp Environment.h
	g++ -c Environment.cpp -Wall -Wextra -o Environment.o --std=c++11 -g
	
Life.o: Life.cpp Life.h
	g++ -c Life.cpp -Wall -Wextra -o Life.o --std=c++11 -g
	
Image.o: Image.cpp Image.h
	g++ -c Image.cpp -Wall -Wextra -o Image.o --std=c++11 -g

clean:
	rm -f *.o
