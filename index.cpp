#include <iostream>
#include "myhash.cpp"
#include <fstream> 
#include <windows.h>
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
	Sleep(2000);
	cout << "EVERYTHING ARE READY";
}

string checkInput(string line){
	int last = line.length();
	while(1){
		last--;
		if(line[last] == 32) line = line.substr(0,last);
		else break;
	}
	while(1){
		if(line[0] == 32) line = line.substr(1,last);
		else break;
	}
	return line;
}

void findWord(){
	fflush(stdin);
	do{ 
    	cout << "\n\n               Chuc nang da chon: Tim tu. \n\n";
		cout << "               Nhap tu muon tim kiem hoac nhap 0 de thoat: ";
		string name;
		fflush(stdin);
		getline(cin,name);
		name = checkInput(name);
		if(name == "0") {
	        system("cls");
			break;
	    }   
		cout << myhash.getValueByName(name);
		getchar();
		system("cls");
	}while(1);
}

void sayHello(){
	Sleep(3000);
	system("cls");
	cout <<"\n\n\n";
	cout <<"                    *      *      ------*      *         *           *------\n";
	cout <<"                    |______|      |_____       |         |           /      \\\n";
	cout <<"                    |      |      |_____       |____     |____       \\______/\n";
	Sleep(800);
	system("cls");
}
void sayGoodbye(){
	cout <<"\n\n";
	cout <<"            ------*      *------      *------      *------            *------      *      *      ------*\n";
	cout <<"            |    ___     /      \\     /      \\      |     \\            |____/        \\___/       |_____\n";
	cout <<"            |_____|      \\______/     \\______/      |_____/            |____\\          |         |_____\n";
    cout <<"\n\n";
    Sleep(800);
}

void menu(){
	system("COLOR 0A");
	string choose;
	int choose1;
	sayHello();
	while(choose1!=12){
		cout << "\n\n\n\t                H2T DICT: \n\n" << endl;
		cout << "\t                    1. Tim tu.  " << endl;
		cout << "\t                    2. Thoat chuong trinh. \n\n" << endl;
		fflush(stdin);
		cin >> choose;
		choose = checkInput(choose);
		choose1 = atoi(choose.c_str());
		if( choose1 == 0) {
		    system("cls");
		    cout << "Moi nhap lai!" << endl;
			continue;	    
	    }
	    else {
	        system("cls");
		    switch(choose1){
			    case 1: cin.ignore(); findWord(); break;
			    case 2: sayGoodbye(); exit(1); break; 
			    default: cout << "Moi nhap lai!" << endl;
		    }
	    }
		fflush(stdin);		
	}
}

int main(){
	readFile();
	menu();
	return 0;
}
