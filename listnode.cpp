#include <iostream>
using namespace std;

class ListNode{
	public:
		string name;
		string value;
		string description;
		string example;
		ListNode *next = NULL;
		ListNode();
		ListNode(string, string);
		ListNode(string, string, string, string);
		~ListNode();
};

ListNode::ListNode(){
	this->name = "";
	this->value = "";
	this->description = "";
	this->example = "";
}

ListNode::ListNode(string name, string value){
	this->name = name;
	this->value = value;
}

ListNode::ListNode(string name, string value, string description, string example){
	this->name = name;
	this->value = value;
	this->description= description;
	this->example = example;
}

ListNode::~ListNode(){
	this->next = NULL;
}
