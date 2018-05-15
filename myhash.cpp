#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "baselist.cpp"
#include "mystring.cpp"
using namespace std;

class MyHash{
	public:
		BaseList bhm[26];
		MyHash();
		~MyHash();
		bool insertNode(string, string);
};

MyHash::MyHash(){
	if(bhm == NULL){
		cout << "CREATED HASH MAP FAILED\n";
	} 
	cout << "CREATED HASH MAP SUCCESS\n";
}

MyHash::~MyHash(){
	for(int i = 0; i < 26; i++)
		free(bhm[i].next);
	cout << "\nDROP HASH MAP SUCCESS\n";
}

bool MyHash::insertNode(string name, string value){
	cout << "INSERT NODE: " << name << " - " << value << endl;
	ListNode *ln;
	ListNode ln0;
	ln = & ln0;
	if(ln == NULL){
		cout << "MALLOC listnode FAILED\n";
		return false;
	}
	if(name == "" || value == ""){
		cout << "ERROR: NULL INPUT\n";
		return false;
	}
	name = cleanSpace(toLowerStr(name));
	value = cleanSpace(toLowerStr(value));
	if(name == "" || value == ""){
		cout << "ERROR: NULL INPUT\n";
		return false;
	}
	ln->name = name;
	ln->value = value;
	cout <<"Hash to: "<< tolower(name[0])-97 << endl;
	cout << "Insert to list success: " << this->bhm[tolower(name[0])-97].insertNode(ln) << endl;
	return true;
}

