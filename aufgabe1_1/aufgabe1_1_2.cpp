/*
	2. Wie funktioniert heap sort. Implementieren Sie heap sort mit Hilfe der bekannten Daten-
	strukturen. Argumentieren Siewarum derAlgorithmus worst-case Komplexit¨at O(nlogn)
	besitzt.
*/

#include <algorithm>
#include <ctime>
#include "heap.h"

using namespace std;

template<typename T>
void fillHeap(Heap<T> &h,int x){
	srand(time(0));
	for(int i=0; i<x; i++){
		h.push(rand()%100);
	}
}


int main(){


	Heap<int> heap (10);
	fillHeap<int>(heap, 10);
	heap.print();

	cout<<endl;

	heap.sort();
	heap.print();
	
	return 0;
}