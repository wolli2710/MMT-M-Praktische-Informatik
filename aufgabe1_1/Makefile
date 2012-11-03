#DIRS = $$(ls -d -- */)
#H_FILES = $$(wildcard **/*.h)
#CPP_FILES = $$(wildcard *.cpp)
	
all: aufgabe1_1_1 aufgabe1_1_2 aufgabe1_1_3

aufgabe1_1_1: uebung1/*.cpp
	$(CXX) -Wall -g -o $@ uebung1/*.cpp 
aufgabe1_1_2: uebung2/*.cpp
	$(CXX) -Wall -g -o $@ uebung2/*.cpp 
aufgabe1_1_3: uebung3/*.cpp
	$(CXX) -Wall -g -o $@ uebung3/*.cpp 

test: all
	./aufgabe1_1_1 
	./aufgabe1_1_2 
	./aufgabe1_1_3 

clean: 
	rm -f aufgabe1_1_1
	rm -f aufgabe1_1_2
	rm -f aufgabe1_1_3