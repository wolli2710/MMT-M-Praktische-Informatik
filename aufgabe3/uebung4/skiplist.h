#ifndef SKIPLIST_H_
#define SKIPLIST_H_

#include <iostream>
#include <stdlib.h>
#include "skipnode.h"

template<typename V>
class SkipList {

  public:
      SkipList(int _maxLevel): maxLevel(_maxLevel) {
          head = new SkipNode<V>(-1, maxLevel);
      }
      
      ~SkipList(){
        clearSkipNode(head);
      }

    void clearSkipNode(SkipNode<V> *node){
      if(!node) return;
      clearSkipNode(node->forward[0]);
      delete node;
    }

      V search(V searchKey) { 
        SkipNode<V> *x = head;                  
        for (int i=maxLevel; i>=0; i--)
          while ((x->forward[i] != NULL) &&
                 (x->forward[i]->value < searchKey))
            x = x->forward[i];
        x = x->forward[0];  
        if ((x != NULL) && (x->value == searchKey)) return x->value;
        else return -1;
      }

      void insert(V newValue) { 
        // We don't want to store duplicates 
        if(search(newValue) != -1) return;
        
        // Start at header node
        SkipNode<V> *x = head;   
                
        int newLevel = randomLevel();

        // update contains pointers to the rightmost nodes that are to the left of the insertion
        SkipNode<V>* update[maxLevel+1];    
        for(int i=maxLevel; i>=0; i--) { 
          while((x->forward[i] != NULL) && (x->forward[i]->value < newValue)){
            x = x->forward[i];
          }
          update[i] = x;
        }
        // Create new node
        x = new SkipNode<V>(newValue, newLevel);
        
        // update pointers
        for (int i=0; i<=newLevel; i++) {
          x->forward[i] = update[i]->forward[i];
          update[i]->forward[i] = x;             
        }
      }
      
      void print() {
          for (SkipNode<V>* iterator = head->forward[0]; iterator!= NULL; iterator = iterator->forward[0]) {
              std::cout << iterator->value << std::endl;
        } 
      }

  private:
      SkipNode<V>* head;
      int maxLevel;

      int randomLevel() { 
        int level;
        for (level=0; (( random()%2 ) == 0); level++); 
        return (level > maxLevel) ? maxLevel : level;
      }
};

#endif

