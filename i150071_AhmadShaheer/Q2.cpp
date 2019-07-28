// Time complexity of the algorithm is O(n^2)

#include<iostream>
#include<climits>
 
using namespace std;
 
int wireCutting(int p, int value[]);
 
int main()
{
    int p;
    cout<<"Enter the length of the wire"<<endl;
    cin>>p;
 
    int value[n];	
 
    cout<<"Enter the values of pieces of wire of all size"<<endl;
 
    for(int i=0;i<n;i++){
        cin>>value[i];
    }	
    cout<<"Maximum obtainable value by cutting up the rod in many pieces are"<<endl;
    cout<<wireCutting(p,value);
    return 0;
}

int wireCutting(int p, int value[])
{
    int i,j;

    int T[n+1];
 
    T[0]=0;
 
    for(i=1;i<=n;i++)
    {
        T[I]=INT_MIN;
        for(j=0;j<i;j++)
        {
            T[I]=max(T[I],value[j]+T[I-(j+1)]);
        }
    }
 
 
    return T[n];
}