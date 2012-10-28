#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

#include "tree.cpp"
#include "avl_tree.cpp"
#include "heap.h"
#include "CustomDataType.h"
#include <algorithm>
#include <ctime>


using namespace std;


template<typename T>
void fillHeap(Heap<T> &h,int x);

template<typename T>
void fillTree(int x, T *t);

void aufgabe1_1_1();
void aufgabe1_1_2();
void aufgabe1_1_3();


int main(){

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
  cout<<endl<<"################"<<endl;
  

  return 0;
}


template<typename T>
void fillHeap(Heap<T> &h,int x){
  srand(time(0));
  for(int i=0; i<x; i++){
    h.push(rand()%100);
  }
}

template<typename T>
void fillTree(int x, T *t){
  srand ( time(NULL) );
  int randomNumber;

  for(int i=0; i<x; i++){
    randomNumber = rand() % 100000 + 1;
    t->insert(randomNumber);
  }
}

void aufgabe1_1_1(){
  Heap<int> heap (20);
  fillHeap<int>(heap, 10);
  heap.print();

  Heap<CustomDataType*> heap2 (20);

  CustomDataType a1 (2.9);
  CustomDataType a2 (4.8);
  CustomDataType a3 (1.9);
  CustomDataType a4 (9.7);

  heap2.push(&a1);
  heap2.push(&a2);
  heap2.push(&a3);
  heap2.push(&a4);
  heap2.print();

  cout<< (a1 < a2);
}

void aufgabe1_1_2(){
  Heap<int> heap (10);
  fillHeap<int>(heap, 10);
  heap.print();

  cout<<endl;

  heap.sort();
  heap.print();
}

void aufgabe1_1_3(){
  Tree t1;
  fillTree<Tree>(10, &t1);
  t1.print();
  t1.printHeight();

  AvlTree t2;
  fillTree<AvlTree>(10, &t2);
  t2.print();
  t2.printHeight();
}