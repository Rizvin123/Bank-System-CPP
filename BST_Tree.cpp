#include "BST_Tree.h"
#include "Hashtable.h"
BST_Tree::BST_Tree(){

}
void BST_Tree::add_Account(string name, string address, int accountno, int password, int balance){
    h.add(accountno, password);
    ofstream write;
    write.open("server.txt",ios::app);
    write << name <<endl << address << endl << accountno << endl << password << endl << balance << endl;
    write.close();

    BST_Node *temp = new BST_Node(name, address, accountno, password, balance);

    BST_Node *current = Root;
    if(Root == NULL){
        Root = temp;
    }
    else{
        while(true){
            if(accountno < current->account_number){
                if(current->left == NULL){
                    current->left = temp;
                    break;
                }
                current = current->left;
            }

            if(accountno > current->account_number){
                if(current->right == NULL){
                    current->right = temp;
                    break;
                }
                current = current->right;
            }
        }
    }
}

BST_Node* BST_Tree::delete_Account(BST_Node *root, int accountno){
    if(root == NULL){
        cout<< "You have Entered Incorrect Account Number\n";
    }
    else if(accountno < root->account_number){
        root->left = delete_Account(root->left, accountno);
    }
    else if(accountno > root->account_number){
        root->right = delete_Account(root->right, accountno);
    }
    else{
        if(root->left && root->right){
            findMax(root->left);
            root->account_number = v.back();
            root->left = delete_Account(root->left,root->account_number);
        }
        else{
            BST_Node* temp = root;
            if(root->left) root = root->left;
            if(root->right) root = root->right;
            delete temp;
        }
    }

    return root;
}

void BST_Tree::withdraw(int accountno, int amount){
    load_Server();
    BST_Node *temp = search(Root, accountno);
    temp->balance = temp->balance - amount;
    vector<int> data;
    ifstream read;
    read.open("transaction.txt",ios::app);
    int line = 0;
    while(!read.eof()){
        read>>line;
        if(line == accountno){
            data.push_back(line);
            line = (amount*-1);
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for(int i=0; i<data.size(); i++){
        write<<data[i]<<endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");

    update_server(Root);
}

void BST_Tree::deposit(int accountno, int amount){
    load_Server();
    BST_Node *temp = search(Root, accountno);
    temp->balance = temp->balance + amount;

    vector<int> data;
    ifstream read;
    read.open("transaction.txt", ios::app);
    int line = 0;
    while(!read.eof()){
        read>>line;
        if(line == accountno){
            data.push_back(line);
            line = amount;
        }
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for(int i=0; i<data.size(); i++){
        write<<data[i]<<endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");

    update_server(Root);
}

void BST_Tree::editaccount_byAdmin(){

}

void BST_Tree::transfer(int sender_accountno, int receiver_accountno, int sender_amount){
    BST_Node *sender = search(Root, sender_accountno);
    sender->balance = sender->balance - sender_amount;
    BST_Node *receiver = search(Root, receiver_accountno);
    receiver->balance = receiver->balance + sender_amount;

    vector<int> data;
    ifstream read;
    read.open("transaction.txt", ios::app);
    int line = 0;
    while(!read.eof()){
        read>>line;
        if(line == sender_accountno){
            data.push_back(line);
            line = (sender_amount*-1);
        }
        else if (line == receiver_accountno)
		{
			data.push_back(line);
			line = sender_amount;
		}
        data.push_back(line);
    }
    read.close();

    ofstream write;
    write.open("temp.txt", ios::app);
    for(int i=0; i< data.size(); i++){
        write<<data[i]<<endl;
    }
    write.close();
    remove("transaction.txt");
    rename("temp.txt", "transaction.txt");
}

void BST_Tree::transaction_history()
{
    
}

void BST_Tree:: findMax(BST_Node* root)
{
	if (root)
	{
		findMax(root->left);
		v.push_back(root->account_number);
		findMax(root->right);
	}
}

void BST_Tree::load_Server()
{
	ifstream read;
	read.open("server.txt", ios::app);

	string name = "";
	string address = "";
	int accountno = 0;
	int password = 0;
	int balance = 0;
	//cin.ignore();
	while (!read.eof())
	{
		
		
		
		getline(read, name);
		getline(read, address);
		read >> accountno;
		read >> password;
		read >> balance;
		read.ignore();
		read.ignore();

		if (name!="" && address != "" && accountno != 0 && password != 0 )
		{
			//cout << "enter hua" << endl;
			BST_Node * temp = new BST_Node(name, address, accountno, password, balance);
			BST_Node * current = Root;
			if (Root == nullptr)
			{

				Root = temp;
			}
			else
			{
				while (true)
				{

					if (accountno < current->account_number)
					{
						if (current->left == nullptr)
						{
							current->left = temp;
							break;
						}
						current = current->left;
					}

					if (accountno > current->account_number)
					{
						if (current->right == nullptr)
						{
							current->right = temp;
							break;
						}
						current = current->right;
					}
					if (accountno == current->account_number)
					{
						break;
					}
				}
			}
		}
	}
	read.close();
}

void BST_Tree:: update_server(BST_Node *root)
{
	static int i = 0;
	if (i == 0)
	{
		i++;
		remove("server.txt");
	}
	ofstream write;
	write.open("server.txt");
	if (root)
	{
		update_server(root->left);
		write << root->name<<endl;
		write << root->address<<endl;
		write << root->account_number<<endl;
		write << root->password<<endl;
		write << root->balance<<endl;
		update_server(root->right);
	}
	write.close();
}

BST_Node* BST_Tree:: search(BST_Node* root, int accountno)
{
	if (root == nullptr)
		return (nullptr);
	else if (accountno < root->account_number)
		return (search(root->left, accountno));
	else if (accountno > root->account_number)
		return (search(root->right, accountno));
	return (root);

}

void BST_Tree:: printinfo(BST_Node* root)
{

	if (root)
	{
		printinfo(root->left);
		cout << root->name<< endl;
		cout << root->address<<endl;
		cout << root->account_number<<endl;
		cout << root->password<<endl;
		cout << root->balance<<endl;
		printinfo(root->right);
	}
}

