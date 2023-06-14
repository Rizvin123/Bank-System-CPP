#include "Node.h"

Node::Node(){
    next = NULL;
    pre = NULL;
    data = 0;
}

Node::Node(int d){
    next = NULL;
    pre = NULL;
    this->data = d;
}