#include <iostream>
using namespace std;

class HashNode{
	public:
		string name = NULL;
		string value = NULL;
		HashNode *next = NULL;
		HashNode(string, string);
		~HashNode();
};

HashNode::HashNode(string name, string value){
	this.name = name;
	this.value = value;
}

HashNode::~HashNode(){
	string name = NULL;
	string value = NULL;
	HashNode *next = NULL;
}
