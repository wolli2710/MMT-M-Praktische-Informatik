#include <iostream>
#include <algorithm>
#include <ctime>

#include "heap.h"
#include "custom_data_type.h"

using namespace std;

template<typename T>
void fillHeap(Heap<T> &h,int x);

void aufgabe1_1_1();


int main(){
  srand ( time(NULL) );

  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe1:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_1();

  return 0;
}

template<typename T>
void fillHeap(Heap<T> &h,int x){
  srand(time(0));
  for(int i=0; i<x; i++){
    h.push(rand()%100);
  }
}

void aufgabe1_1_1(){
  Heap<int> heap (20);
  fillHeap<int>(heap, 10);

  Heap<CustomDataType> heap2 (20);

  CustomDataType a1(9);
  CustomDataType a2(5);
  CustomDataType a3(8);
  CustomDataType a4(2);

  heap2.push(a1);
  heap2.push(a2);
  heap2.push(a3);
  heap2.push(a4);

  cout<<"Heap filled with Integers:\n";
  heap.print();
  cout<<endl;
  cout<<"Heap filled with CustomDataType:\n";
  heap2.print();
  cout<<endl;
}