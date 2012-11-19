all: aufgabe2_1 aufgabe2_2

aufgabe2_1: aufgabe2_1.cpp
	$(CXX) -c -Wall aufgabe2_1.cpp
	$(CXX) -L /lib aufgabe2_1.o -o aufgabe2_1 -lrt
aufgabe2_2: aufgabe2_2.cpp
	$(CXX) -c -Wall aufgabe2_2.cpp
	$(CXX) -L /lib aufgabe2_2.o -o aufgabe2_2 -lrt

test: aufgabe2_1 aufgabe2_2
	./aufgabe2_1
	./aufgabe2_2

clean: 
	rm -f aufgabe2_1
	rm -f aufgabe2_2
	rm -f aufgabe2_1.o
	rm -f aufgabe2_2.o