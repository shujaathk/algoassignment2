#include <iostream>
using namespace std;


int move(int a=1,int b=1)
{
    if((a==8)||(b==8))
        return 1;
    return move(a+1,b)+move(a,b+1)+move(a+1,b+1);
}

int main()
{
    cout<<move();
}
