# run with the command: 
# cd "directory of file"
# make                <- run first "all"
# make clean          <- run "clean"
# ./program           <- run the executable

all: main.o Library.o Person.o Book.o
	g++ main.o Library.o Person.o Book.o -o program

main.o: main.cpp Library.hpp Person.hpp Book.hpp
	g++ -c main.cpp

Library.o: Library.cpp Library.hpp Person.hpp Book.hpp
	g++ -c Library.cpp

Person.o: Person.cpp Person.hpp Book.hpp
	g++ -c Person.cpp

Book.o: Book.cpp Book.hpp
	g++ -c Book.cpp

clean:
	rm -f main.o Library.o Person.o Book.o program
