#include<iostream>
using namespace std;
int move(int x,int a,int b)
{
    if((a==x)||(b==x))
        return 1;
    return move(x,a+1,b)+move(x,a,b+1);
}
int main()
{
	int x,a=1,b=1;
	cout<<"Enter Board Size: ";
	cin>>x;
    cout<<"No of shortest Paths: "<<move(x,a,b)<<endl;
}
//Complexity n+m
