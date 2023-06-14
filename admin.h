#pragma once
#include <string.h>
#include "BST_Tree.h"
#include "Hashtable.h"
void admin()
{
    BST_Tree t;
    Hashtable h;
    int condition = 0;
    while(condition != 6){
        cout<<"Welcome Admin \n";
        cout<<"Choose the following please \n";
        cout<<"Press 1 to add account \n";
        cout<<"Press 2 to delete account \n";
        cout<<"Press 3 to check all account \n";
        cout<<"Press 4 to see password of account \n";
        cout<<"Press 5 to edit account \n";
        cout<<"Press 6 to exit \n";
        cin>>condition;
        if (condition == 1){
            string n = "", a ="";
            int acc, p, b;
            cout<<"Enter name \n";
            cin>>n;
            cout<<"Enter Address \n";
            cin>>a;
            cout<<"Enter Account number \n";
            cin>>acc;
            cout<<"Enter Password \n";
            cin>>p;
            cout<<"Enter Balance"<<endl;
            cin>>b;
            t.add_Account(n, a, acc, p, b);
        }
        if (condition == 2){
            int acc = 0;
            cout<< "Enter Account Number \n";
            cin>>acc;
            t.load_Server();
            t.Root = t.delete_Account(t.Root,acc);
            h.delete_password(acc);
            t.update_server(t.Root);
        }
        if (condition == 3){
            t.load_Server();
            t.printinfo(t.Root);
        }
        if (condition == 4){
            h.displayPasswords();
        }
        if (condition == 5){

        }
        if (condition == 6){
            condition = 6;
        }
    }
}