#include <iostream>
#include <algorithm>
#include <ctime>

#include "heap.h"

using namespace std;

template<typename T>
void fillHeap(Heap<T> &h,int x);

void aufgabe1_1_2();

int main(){
  srand ( time(NULL) );

  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe2:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_2();

  return 0;
}

template<typename T>
void fillHeap(Heap<T> &h,int x){
  srand(time(0));
  for(int i=0; i<x; i++){
    h.push(rand()%100);
  }
}

void aufgabe1_1_2(){
  Heap<int> heap (10);
  fillHeap<int>(heap, 10);
  cout << "unsorted:\n";
  heap.print();
  cout<<endl;

  heap.sort();
  cout << "sorted:\n";
  heap.print();
}