#include<iostream>

using namespace std;

int gcd(int a,int b){
	if(b>a) return gcd(b,a);
	if(b==0) return a;
	return gcd(a%b,b);
}

int main(){
	int a,b;
	cout<<"Enter two numbers a and b : ";
	cin>>a>>b;
	cout<<"GCD of a and b is : "<<gcd(a,b)<<endl;
	return 0;
}
