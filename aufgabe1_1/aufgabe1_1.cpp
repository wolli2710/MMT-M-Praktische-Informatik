#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <ctime>

#include "tree.cpp"
#include "avl_tree.cpp"
#include "heap.cpp"
#include "custom_data_type.cpp"

using namespace std;

template<typename T>
void fillHeap(Heap<T> &h,int x);

void aufgabe1_1_1();
void aufgabe1_1_2();
void aufgabe1_1_3();

int main(){
  srand ( time(NULL) );

  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe1:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_1();
  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe2:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_2();
  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe3:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_3();
  cout<<endl<<endl;
  
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

void aufgabe1_1_3(){
  Tree t1;
  AvlTree t2;

  int counter = 1;
  do{
    unsigned randomNumber = rand() % 100000;
    t1.insert(randomNumber);
    t2.insert(randomNumber);
    if(counter % 10000==0&&counter>1){
      cout<<counter<<" Elements =>\n";
      cout<<"Tree height:    "<<t1.height()<<endl;
      cout<<"AvlTree height: "<<t2.height()<<endl<<endl;
    }
    counter++;
  }
  while(counter <= 30000);
}