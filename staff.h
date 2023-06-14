#pragma once
# include "BST_Tree.h"
# include "Hashtable.h"

void staff(){
    BST_Tree t;
	Hashtable h;
	int condition = 0;
	while (condition != 5){
		cout << "Welcome STAFF" <<"\n";
		cout << "Kindly Choose From the following" <<"\n";
		cout << "Press 1 to see Transaction history  " <<"\n";
		cout << "Press 2 to Transfer " <<"\n";
		cout << "Press 3 to Withdraw " <<"\n";
		cout << "Press 4 to Deposit " <<"\n";
		cout << "Press 5 to Exit" <<"\n";
		cin >> condition;
        if (condition == 1)
		{
			// Print Transaction file or display transaction file related to an account
		}
        if (condition == 2)
		{
			int senderaccountno = 0, amount = 0, recieveraccountno=0;
			cout << "Enter sender account number" <<"\n";
			cin >> senderaccountno;
			cout << "Enter receiver account number" <<"\n";
			cin >> recieveraccountno;
			cout << "Enter amount" <<"\n";
			cin >> amount;
			t.transfer(senderaccountno,amount,recieveraccountno);
		}
        if (condition == 3)  // withdraw
		{
			int accountno = 0, amount = 0;
			cout << "Enter account number" << "\n";
			cin >> accountno;
			cout << "Enter amount" << "\n";
			cin >> amount;
			t.withdraw(accountno, amount);
		}
        if (condition == 4)
		{
			int accountno = 0, amount = 0;
			cout << "Enter account number" << "\n";
			cin >> accountno;
			cout << "Enter amount" << "\n";
			cin >> amount;
			t.deposit(accountno, amount);
		}
        if (condition == 5)
		{
			condition = 5;
		}
    }
}