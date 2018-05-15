#include <iostream>
#include "listnode.cpp"
using namespace std;

class BaseList{
	public:
		int countNode;
		ListNode *next;
		BaseList();
		bool insertNode(ListNode*);
		void printList();
};

BaseList::BaseList(){
	this->countNode = 0;
	this->next = NULL;
}

bool BaseList::insertNode(ListNode *hn){
	cout << "Insert node";
	ListNode *temp;
	temp = this->next;
	while(temp != NULL) temp = temp->next;
	temp = hn;
	countNode++;
	cout << "Listnode count: " << countNode << endl;
	return true;
}


