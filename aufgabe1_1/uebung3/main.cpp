#include <iostream>
#include <algorithm>
#include <ctime>

#include "tree.h"
#include "avl_tree.h"

using namespace std;

void aufgabe1_1_3();

int main(){
  srand ( time(NULL) );

  cout<<endl<<"################"<<endl;
  cout<< "Aufgabe3:";
  cout<<endl<<"################\n"<<endl;
  aufgabe1_1_3();
  cout<<endl<<endl;
  
  return 0;
}

void aufgabe1_1_3(){
  Tree<double> t1;
  AvlTree<double> t2;

  for(int i=1; i<= 30000; i++){
    unsigned randomNumber = rand() % 100000;
    t1.insert(randomNumber);
    t2.insert(randomNumber);
    if(i % 10000==0&&i>1){
      cout<< i <<" Elements =>\n";
      cout<<"Tree height:    "<<t1.height()<<endl;
      cout<<"AvlTree height: "<<t2.height()<<endl<<endl;
    }
  }
}