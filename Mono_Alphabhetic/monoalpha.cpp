#include<bits/stdc++.h>

using namespace std;

class Mono_Alphabetic{
public:
	unordered_map<char,char>encrypt_key;
	unordered_map<char,char>decrypt_key;
	
	Mono_Alphabetic(unordered_map<char,char>encrypt_key,unordered_map<char,char>decrypt_key){
		this->encrypt_key = encrypt_key;
		this->decrypt_key = decrypt_key;
	}
	string Encryption(string str){
		string ans = "";
		for(int i=0; i<str.size(); i++){
			char ch = str[i];
			if(ch >= 'A' && ch <= 'Z'){
				ans += encrypt_key[ch];
			}
			else if(ch >= 'a' && ch <= 'z'){
				ans += encrypt_key[ch];
			}
			else if(ch >= '0' && ch <= '9'){
				ans += encrypt_key[ch];
			}
			else {
				ans += ch;
			}
		}
		return ans;
	}
	string Decryption(string str){
		string ans = "";
		for(int i=0; i<str.size(); i++){
			char ch = str[i];
			if(ch >= 'A' && ch <= 'Z'){
				ans += decrypt_key[ch];
			}
			else if(ch >= 'a' && ch <= 'z'){
				ans += decrypt_key[ch];
			}
			else if(ch >= '0' && ch <= '9'){
				ans += decrypt_key[ch];
			}
			else {
				ans += ch;
			}
		}
		return ans;
	}
			
};

int main(){
	unordered_map<char,char>encrypt_key;
	unordered_map<char,char>decrypt_key;
	
	ifstream k("key.txt");
	string line;
	while(getline(k,line)){
		char a = line[0];
		char b = line[2];
		encrypt_key[a] = b;
		decrypt_key[b] = a;
	}
	
	k.close();
	
	Mono_Alphabetic* monoAlphabetic = new Mono_Alphabetic(encrypt_key,decrypt_key);
	
	ifstream file("plain.txt");
	ofstream fout("encrpt.txt");
	string word;
	while(getline(file,word)){
		string s = monoAlphabetic->Encryption(word);
		fout<<s<<endl;
	}
	file.close();
	fout.close();
	
	ifstream FILE("encrpt.txt");
	ofstream FOUT("decrpt.txt");
	string line;
	while(getline(FILE,line)){
		string s = monoAlphabetic->Decryption(line);
		FOUT<<s<<endl;
	}
	FILE.close();
	FOUT.close();
	
	return 0;	
}
