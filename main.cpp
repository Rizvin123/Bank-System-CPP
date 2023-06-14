#include "Hashtable.h"
#include "BST_Tree.h"
#include "admin.h"
#include "staff.h"
#include "customer.h"
#include "string.h"

void boot(){
    Hashtable H;
    BST_Tree T;
    H.starthash();
    T.load_Server();
}
int main(){
    void boot();
    int condition=0;
    while (condition != 4)
	{
		cout << "YOU want to login as:" << "\n" << "\n";
		cout << "1-ADMIN" << "\n";
		cout << "2-STAFF" << "\n";
		cout << "3-CUSTOMER" << "\n";
		cin >> condition;
		if (condition == 1)
		{
			admin();
		}
		if (condition == 2)
		{
            staff();
		}
		if (condition == 3)
		{
			customer();
		}
		if (condition == 4)
		{
			condition = 4;
		}
	}
	system("pause");
	return 0;
}
