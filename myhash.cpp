#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include "baselist.cpp"
using namespace std;

class MyHash{
	public:
		BaseList bhm[26];
		MyHash();
		~MyHash();
		bool insertNode(string, string, string, string);
		string getValueByName(string);
};

MyHash::MyHash(){
	if(bhm == NULL){
		cout << "CREATED HASH MAP FAILED\n";
	} 
	cout << "CREATED HASH MAP SUCCESS\n";
}

MyHash::~MyHash(){
	for(int i = 0; i < 26; i++)
		free(bhm[i].baseNode);
	cout << "\nDROP HASH MAP SUCCESS\n";
}

bool MyHash::insertNode(string name, string value, string des, string exp){
	cout << "INSERT NODE: " << name << endl;
	cout <<"Hash to: "<< tolower(name[0])-97 << endl;
	cout << "Insert to list success: " << this->bhm[tolower(name[0])-97].insertNode(name, value, des, exp) << endl;
	return true;
}

string MyHash::getValueByName(string name){
	name = cleanSpace(toLowerStr(name));
	return this->bhm[name[0]-97].getValue(name);
}
