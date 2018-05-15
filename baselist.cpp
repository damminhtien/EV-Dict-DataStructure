#include <iostream>
#include "listnode.cpp"
#include "mystring.cpp"
using namespace std;

class BaseList{
	public:
		int countNode;
		ListNode *baseNode;
		BaseList();
		bool insertNode(string, string, string, string);
		string getValue(string);
		void printList();
};

BaseList::BaseList(){
	this->countNode = 0;
	this->baseNode = NULL;
}

bool BaseList::insertNode(string name, string value, string des, string exp){
	cout << "Insert node - " << endl;
	name = cleanSpace(toLowerStr(name));
	value = cleanSpace(toLowerStr(value));
	des = cleanSpace(toLowerStr(des));
	exp = cleanSpace(toLowerStr(exp));
	ListNode *ln = new ListNode(name, value, des, exp);
	if(ln == NULL){
		cout << "MALLOC listnode FAILED\n";
		return false;
	}
	cout << "MALLOC listnode SUCCESS\n";
	if(name == "" || value == ""){
		cout << "ERROR: NULL INPUT\n";
		return false;
	}
	if(name == "" || value == ""){
		cout << "ERROR: NULL INPUT\n";
		return false;
	}
	cout << "UPDATE listnode SUCCESS\n";
	if(this->baseNode == NULL) this->baseNode = ln;
	else{
		ListNode *temp;
		temp = this->baseNode;
		while(temp->next != NULL) temp = temp->next;
		temp->next = ln;
		cout << "Base Node: " << this->baseNode->name << endl;
	}
	countNode++;
	cout << "Listnode count: " << countNode << endl;
	return true;
}

string BaseList::getValue(string name){
	cout << "\nFind " << name << " in " << countNode << " elements of listbase" << endl;
	ListNode *temp;
	temp = this->baseNode;
	while(temp != NULL && temp->name != name){
		temp = temp->next;
	}
	if(temp == NULL){
		cout << "Not found" << endl;
		return "";
	}
	cout << "\t Nghia: " << temp->value << endl;
	cout << "\t Vi du: " << temp->example << endl;
	cout << "\t Cach su dung: " << temp->description << endl;
	return temp->value;
}
