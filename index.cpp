#include <iostream>
#include "myhash.cpp"
#include <fstream> 
#include <windows.h>
using namespace std;

MyHash myhashEV;
MyHash myhashVE;

void readFile(){
	ifstream fi("dict.txt");
	string line;
	while(!fi.eof()){
		getline(fi,line);
		if(line == "") break;
		int i = 0, j = 0;
		while(line[i] != '@'){
			i++;
		}
		string name = line.substr(0, i);
		i++; 
		j = i;
		while(line[i] != '@'){
			i++;
		}
		string value = line.substr(j, i-j);
		i++; 
		j = i;
		while(line[i] != '@'){
			i++;
		}
		string des = line.substr(j, i-j);
		i++; 
		j = i;
		while(line[i] != '\0'){
			i++;
		}
		string exp = line.substr(j, i-j);
		cout << "\nREAD WORD: " << name << " - " << value << " - " << des << " - " << exp << endl;
		cout << "Insert to hash EV success: " << myhashEV.insertNode(name, value, des, exp) << endl;
		cout << "Insert to hash VE success: " << myhashVE.insertNode(value, name, des, exp) << endl;
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

void findWord(int flag){
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
		if(flag == 0) myhashEV.getValueByName(name);
		else myhashVE.getValueByName(name);
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
		cout << "\t                    1. Tim tu E-V.  " << endl;
		cout << "\t                    2. Tim tu V-E.  " << endl;
		cout << "\t                    3. Thoat chuong trinh. \n\n" << endl;
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
			    case 1: cin.ignore(); findWord(0); break;
			    case 2: cin.ignore(); findWord(1); break;
				case 3: sayGoodbye(); exit(1); break; 
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
