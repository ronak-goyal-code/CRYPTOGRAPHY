#include<iostream>

using namespace std;

int gcd(int a,int b,int& x,int& y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	int x1,y1;
	int Gcd = gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1 * (a / b);
    return Gcd;
}

int main(){
	int a,b;
	cout<<"Enter two numbers a and b : ";
	cin>>a>>b;
	int GCD;
	int x,y;
	if(a>b) GCD = gcd(a,b,x,y);
	else GCD = gcd(b,a,x,y);
	cout<<"GCD of a and b is : "<<GCD<<endl;
	return 0;
}
