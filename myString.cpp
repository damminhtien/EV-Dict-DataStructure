#include <iostream>
using namespace std;

string toLowerStr(string s){
	int i = 0;
	while(s[i] != '\0') {
      s[i] = tolower(s[i]);
      i++;
   }
   return s;
}

bool operator > (string s1, string s2){
	if(toLowerStr(s1).compare(toLowerStr(s2)) > 0) return true;
	else return false;
} 

bool operator == (string s1, string s2){
	if(toLowerStr(s1).compare(toLowerStr(s2)) == 0) return true;
	else return false;
}

bool operator != (string s1, string s2){
	if(toLowerStr(s1).compare(toLowerStr(s2)) == 0) return false;
	else return true;
}

bool operator < (string s1, string s2){
	if(toLowerStr(s1).compare(toLowerStr(s2)) < 0) return true;
	else return false;
}

string equalTo(string sour){
	string des;
	return des.replace(0,des.length(),sour);
}

string cleanSpace(string s){
	int i = 0;
	int l = s.length();
	while(s[i] == ' '){
		s = s.substr(1,l-1);
		l--;
	}
	while(s[i] != '\0'){
		if(s[i] == ' ' && s[i+1] == ' '){
			int j = i;
			while(s[j] != '\0'){
				s[j] = s[j+1];
				j++;
			}
			l--;
			continue;
		}
		i++;
	}
	while(s[l-1] == ' '){
		s = s.substr(0,l-1);
		l--;
	}
	return s;
}
