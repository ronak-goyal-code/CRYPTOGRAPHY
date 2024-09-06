#include<bits/stdc++.h>

using namespace std;

class PlayFair{
public:
	//vector<vector<char>> grid(5,vector<char> (5,'\0'));
	char grid[5][5];
	string key;
	
	PlayFair(string key){
		this->key = key;
		Generate_grid();
	}
	
	void Generate_grid(){
		unordered_map<char,int> map;
		int i = 0;
		int j = 0;
		for(char k: this->key){
			if(k >= 'a' && k <= 'z') k = k - 32;
			if(map.find(k) == map.end()){
				grid[i][j] = k;
				map[k]++;
				j++;
				if(j%5 == 0){
					i++;
					j=0;
				}
			}
		}
		for(int a=0; a<26; a++){
			if(a == 9) continue;
			if(map.find((char)(a + 65)) == map.end()){
				grid[i][j] = (char)(a + 65);
				map[(char)(a + 65)]++;
				j++;
				if(j%5 == 0){
					i++;
					j=0;
				}
			}
		}
	}
	
	void Display_Grid(){
		cout<<"5 X 5 matrix for given Key is : "<<endl;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	pair<int,int> find_location(char ch){
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(grid[i][j] == ch){
					return {i,j};
				}
			}
		}
		return {-1,-1};
	}
	
	string Algorithm(pair<int,int> a, pair<int,int> b){
		int x1 = a.first;
		int x2 = b.first;
		int y1 = a.second;
		int y2 = b.second;
		
		string s = "";
		
		if(x1 == x2){
			s += grid[x1][(y1+1)%5];
			s += grid[x2][(y2+1)%5];
		}
		
		else if(y1 == y2){
			s += grid[(x1+1)%5][y1];
			s += grid[(x2+1)%5][y2];
		}
		
		else{
			s += grid[x1][y2];
			s += grid[x2][y1];
		}
		
		return s;
	}
	
	string Encryption(string str){
		string ans = "";
		int n = str.size();
		int i = 0;
		while(i<n){
			if(str[i] == ' ') continue;
			char a = str[i];
			char b;
			
			if(i != n-1) b = str[i+1];
			else b = 'Z';
			
			
			
			if(a == b){
				b = 'Z';
				i++;
			}
			else i+=2;
			
			pair<int,int> p1 = find_location(a);
			pair<int,int> p2 = find_location(b);
			
			ans += Algorithm(p1,p2);
		}
		
		return ans;
	}
	
	string Reverse_Algorithm(pair<int,int> a, pair<int,int> b){
		int x1 = a.first;
		int x2 = b.first;
		int y1 = a.second;
		int y2 = b.second;
		
		string s = "";
		
		if(x1 == x2){
			if(y1 == 0) y1 = 5;
			if(y2 == 0) y2 = 5;
			s += grid[x1][y1-1];
			s += grid[x2][y2-1];
		}
		
		else if(y1 == y2){
			if(x1 == 0) x1 = 5;
			if(x2 == 0) x2 = 5;
			s += grid[x1-1][y1];
			s += grid[x2-1][y2];
		}
		
		else{
			s += grid[x1][y2];
			s += grid[x2][y1];
		}
		
		return s;
	}
	
	string Decryption(string str){
		string ans = "";
		int n = str.size();
		int i = 0;
		while(i<n){
			char a = str[i];
			char b = str[i+1];
			
			i += 2;
			
			pair<int,int> p1 = find_location(a);
			pair<int,int> p2 = find_location(b);
			
			ans += Reverse_Algorithm(p1,p2);
		}
		
		return ans;
	}
	
	
};

int main(){
	string key;
	cout<<"Enter key : ";
	getline(cin,key);
	PlayFair* playfair = new PlayFair(key);
	playfair->Display_Grid();
	
	
	/*int c = 1;
	cout<<"Please Enter 1 if you want to do encryption through your key."<<endl;
	cout<<"Please Enter 2 if you want to do decryption through your key."<<endl;
	cout<<"Please Enter 3 for exit."<<endl;
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
			cout<<playfair->Encryption(plainText)<<endl;
		}
		else if(choice == 2){
			string cipherText;
			cout<<"Enter your cipher text : ";
			getline(cin,cipherText);
			cout<<"Your plain text is : ";
			cout<<playfair->Decryption(cipherText)<<endl;
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
	*/
	
	ifstream file("plain.txt");
	ofstream fout("encrpt.txt");
	string word;
	while(getline(file,word)){
		string s = playfair->Encryption(word);
		fout<<s<<endl;
	}
	file.close();
	fout.close();
	
	ifstream FILE("encrpt.txt");
	ofstream FOUT("decrpt.txt");
	string line;
	while(getline(FILE,line)){
		string s = playfair->Decryption(line);
		FOUT<<s<<endl;
	}
	FILE.close();
	FOUT.close();
	
	return 0;
}
