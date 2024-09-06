#include<bits/stdc++.h>

using namespace std;

class Shift_Cipher{
public:
	int key;
	Shift_Cipher(int key){
		this->key = key;
	}
	string Encryption(string str){
		string ans = "";
		for(int i=0; i<str.size(); i++){
			char ch = str[i];
			int var;
			if(ch >= 'A' && ch <= 'Z'){
				var = (int)(ch - 'A');
				var += this->key;
				var %= 26;
				ans += (char)(var + 'a');
			}
			else if(ch >= 'a' && ch <= 'z'){
				var = (int)(ch - 'a');
				var += this->key;
				var %= 26;
				ans += (char)(var + 'a');
			}
			else if(ch >= '0' && ch <= '9'){
				var = (int)(ch - '0');
				var += this->key;
				var %= 10;
				ans += (char)(var + '0');
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
			int var;
			if(ch >= 'A' && ch <= 'Z'){
				var = (int)(ch - 'A');
				var -= this->key;
				if(var < 0) var += 26;
				var %= 26;
				ans += (char)(var + 'a');
			}
			else if(ch >= 'a' && ch <= 'z'){
				var = (int)(ch - 'a');
				var -= this->key;
				if(var < 0) var += 26;
				var %= 26;
				ans += (char)(var + 'a');
			}
			else if(ch >= '0' && ch <= '9'){
				var = (int)(ch - '0');
				var -= this->key;
				if(var < 0) var += 10;
				var %= 10;
				ans += (char)(var + '0');
			}
			else {
				ans += ch;
			}
		}
		return ans;
	}
			
};

int main(){
	int key;
	cout<<"Enter your shift cipher key : ";
	cin>>key;
	Shift_Cipher* shiftCipher = new Shift_Cipher(key);
	
	// if you dont want to read input from file then execute below commented code.
	/*int c = 1;
	cout<<"___________________________________________________________________"<<endl;
	cout<<"| Please Enter 1 if you want to do encryption through your key.    |"<<endl;
	cout<<"| Please Enter 2 if you want to do decryption through your key.    |"<<endl;
	cout<<"| Please Enter 3 for exit.                                         |"<<endl;
	cout<<"|__________________________________________________________________|"<<endl;
	while(c){
		int choice;
		cout<<"Enter your Choice : ";
		cin>>choice;
		cin.ignore();
		if(choice == 1){
			string plainText;
			cout<<"Enter your plain text : ";
			getline(cin,plainText);
			cout<<"Your cipher text is : ";
			cout<<shiftCipher->Encryption(plainText)<<endl;
		}
		else if(choice == 2){
			string cipherText;
			cout<<"Enter your cipher text : ";
			getline(cin,cipherText);
			cout<<"Your plain text is : ";
			cout<<shiftCipher->Decryption(cipherText)<<endl;
		}
		else if(choice == 3){
			cout<<"You are exited"<<endl;
			exit(1);
		}
		
		else{
			cout<<"Invalid Choice try next time"<<endl;
		}
		cout<<"if you want to continue enter 1 else 0 : ";
		int x;
		cin>>x;
		cin.ignore();
		c = x;
	}*/
	
	ifstream file("plain.txt");
	ofstream fout("encrpt.txt");
	string word;
	while(getline(file,word)){
		string s = shiftCipher->Encryption(word);
		fout<<s<<endl;
	}
	file.close();
	fout.close();
	
	ifstream FILE("encrpt.txt");
	ofstream FOUT("decrpt.txt");
	string line;
	while(getline(FILE,line)){
		string s = shiftCipher->Decryption(line);
		FOUT<<s<<endl;
	}
	FILE.close();
	FOUT.close();
	
	return 0;	
}
