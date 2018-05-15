#include <iostream>
#include "myhash.cpp"
#include <fstream> 
using namespace std;

MyHash myhash;

void readFile(){
	ifstream fi("dict.txt");
	string line;
	while(!fi.eof()){
		getline(fi,line);
		int l = line.length();
		int i = 0;
		while(line[i] != '@'){
			i++;
		}
		string name = line.substr(0, i);
		cout << "\nRead word: " << name << " - value: ";
		string value = line.substr(i+1, l-i-1);
		cout << value << endl;
		cout << "Insert to hash success: " << myhash.insertNode(name, value) << endl;
	}
	fi.close();
}

int main(){
	readFile();
	return 0;
}
