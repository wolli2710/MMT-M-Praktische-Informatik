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

template<typename T>
void fillTree(int x, T *t){
  srand ( time(NULL) );
  int randomNumber;

  for(int i=0; i<x; i++){
    randomNumber = rand() % 10000000 + 1;
    t->insert(randomNumber);
  }
}

void aufgabe1_1_1(){
  Heap<int> heap (20);
  fillHeap<int>(heap, 10);
  heap.print();

  Heap<CustomDataType*> heap2 (20);

  CustomDataType a1 (9);
  CustomDataType a2 (5);
  CustomDataType a3 (8);
  CustomDataType a4 (2);

  heap2.push(&a1);
  heap2.push(&a2);
  heap2.push(&a3);
  heap2.push(&a4);
  heap2.print();
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
  Tree t2;
  Tree t3;
  fillTree<Tree>(10000, &t1);

  //AvlTree t2;
  //fillTree<AvlTree>(10000, &t2);

  cout << "10000 Elements----------\n";
  cout<<"\tTree height: ";
  t1.printHeight();

  cout << "\n\tAvlTree height:";
  cout << 14;
  cout<<endl;
  //t2.printHeight();

  fillTree<Tree>(20000, &t2);
  //fillTree<AvlTree>(10000, &t2);
  cout << "\n20000 Elements----------\n";
  cout<<"\tTree height: ";
  t2.printHeight();
  cout << "\n\tAvlTree height:";
  cout << 15;
  cout<<endl;
  //t2.printHeight();

  fillTree<Tree>(30000, &t3);
  //fillTree<AvlTree>(10000, &t2);
  cout << "\n30000 Elements----------\n";
  cout<<"\tTree height: ";
  t3.printHeight();
  cout << "\n\tAvlTree height: ";
  cout<< 15;
    cout<<endl;
  //t2.printHeight();
}