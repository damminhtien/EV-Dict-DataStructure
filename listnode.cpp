#include <iostream>
using namespace std;

class ListNode{
	public:
		string name;
		string value;
		ListNode *next = NULL;
		ListNode();
		ListNode(string, string);
		~ListNode();
};

ListNode::ListNode(){
	this->name = "";
	this->value = "";
}

ListNode::ListNode(string name, string value){
	this->name = name;
	this->value = value;
}

ListNode::~ListNode(){
	this->next = NULL;
}
