#ifndef SKIPNODE_H_
#define SKIPNODE_H_

template<typename V>
class SkipNode{

  public:
    int level;
    V value;

    SkipNode** forward;

    SkipNode(V v, int l){
        value = v;
        level = l;

        forward = new SkipNode* [level+1];
        for (int i=0; i<=level; i++)
            forward[i] = NULL;
    }

    ~SkipNode() { 
      delete [] forward; 
    }
};

#endif