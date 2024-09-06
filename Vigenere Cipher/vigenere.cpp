#include<bits/stdc++.h>

using namespace std;

class Vigenere{
public:
	string key;
	int size;
	
	Vigenere(string k){
		this->key = k;
		this->size = k.size();
		for(int i=0; i<size; i++){
			if(key[i] >= 'a' && key[i] <= 'z'){
				key[i] = key[i] - 32;
			}
		}
	}
	
	
	string Encryption(string str){
		int n = str.size();
		string ans = "";
		int j = 0;
		for(int i=0; i<n; i++){
			if(str[i] == ' ') continue;
			if(str[i] >= 'a' && str[i] <= 'z'){
				str[i] = str[i] - 32;
			}
			int s = (int)(str[i]-'A');
			int k = (int)(key[j%size] - 'A');
			int a = s + k;
			a %= 26;
			ans += (char)('A' + a);
			j++;
		}
		return ans;
	}
	
	
	
	string Decryption(string str){
		int n = str.size();
		string ans = "";
		int j = 0;
		for(int i=0; i<n; i++){
			if(str[i] == ' ') continue;
			if(str[i] >= 'a' && str[i] <= 'z'){
				str[i] = str[i] - 32;
			}
			int s = (int)(str[i]-'A');
			int k = (int)(key[j%size] - 'A');
			int a = s - k;
			a += 26;
			a %= 26;
			ans += (char)('A' + a);
			j++;
		}
		return ans;
	}
	
	
};

int main(){
	string key;
	cout<<"Enter key : ";
	getline(cin,key);
	Vigenere* vigenere = new Vigenere(key);
	
	//string ans = vigenere->Encryption("BLACKbOARD");
	//cout<<vigenere->Decryption(ans);
	
	
	int c = 1;
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
			cout<<vigenere->Encryption(plainText)<<endl;
		}
		else if(choice == 2){
			string cipherText;
			cout<<"Enter your cipher text : ";
			getline(cin,cipherText);
			cout<<"Your plain text is : ";
			cout<<vigenere->Decryption(cipherText)<<endl;
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
	}
	
	/*ifstream file("plaine.txt");
	ofstream fout("encrpt.txt");
	string word;
	while(getline(file,word)){
		string s = vigenere->Encryption(word);
		fout<<s<<endl;
	}
	file.close();
	fout.close();
	
	ifstream FILE("encrpt.txt");
	ofstream FOUT("decrpt.txt");
	string line;
	while(getline(FILE,line)){
		string s = vigenere->Decryption(line);
		FOUT<<s<<endl;
	}
	FILE.close();
	FOUT.close();*/
	
	return 0;
}
