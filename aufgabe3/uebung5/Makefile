#DIRS = $$(ls -d -- */)
#H_FILES = $$(wildcard **/*.h)
#CPP_FILES = $$(wildcard *.cpp)
	
all: main

aufgabe1_1_1: main.cpp
	$(CXX) -Wall -g -o $@ main.cpp 

test: all
	./main 
	
clean: 
	rm -f main
	
valgrind:
	valgrind --leak-check=yes ./main