#include "BST_Node.h"

BST_Node::BST_Node()
{
    left = nullptr;
    right = nullptr;
    name = "";
    address = "";
    account_number = 0;
    password = 0;
    balance = 0;
}

BST_Node::BST_Node(string name, string address, int accountno,int password, int balance){
    left = NULL;
    right = NULL;
    this->name = name;
    this->address = address;
    this->account_number = accountno;
    this->password = password;
    this->balance = balance;
}