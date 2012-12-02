/**
 * @author Wolfgang Vogl, Franz Torghele, Katrin Hewer 
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "skiplist.h"
#include "tree.h"

#define ITERATIONS 1000

using namespace std;

int main(){
    srand(time(NULL));

  Tree<double> t;
  SkipList<double> s(9);

  for(int i =0; i<ITERATIONS; i++){
    double r = (float) rand()/RAND_MAX;
    t.insert(r);
    s.insert(r);
  }
  
  s.print();
  std::cout << "----------------------" << std::endl;
  t.print();

  return 0;

}