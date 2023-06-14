#pragma once
#include "BST_Tree.h"
#include "Hashtable.h"
void customer(){
    BST_Tree t;
    Hashtable h;
    int condition = 0;
    while(condition != 3){
        cout<<"Welcome Customer \n";
        cout << "Kindly Choose from the Following \n";
		cout << "Press 1 to see Account details \n";
		cout << "Press 2 to see Transaction history \n";
		cout << "Press 3 to exit \n";
        cin>>condition;
        if(condition == 1){
            int accountno;
            cout<<"Please Enter Account Number \n";
            cin>>accountno;
            BST_Node* temp = t.search(t.Root,accountno);
            cout << "Account Details Are : \n\n";
			cout << "NAME :" << temp->name <<"\n";
			cout << "ADRESS :" << temp->address <<"\n";
			cout << "ACCOUNT NUMBER :" << temp->account_number <<"\n";
			cout << "PASSWORD :" << temp->password <<"\n";
			cout << "BALANCE :" << temp->balance <<"\n";
        }
        if (condition == 2)
		{
			// Print Transaction file or display transaction file related to an account
		}
		if (condition == 3)
		{
			condition = 3;
		}
    }
}