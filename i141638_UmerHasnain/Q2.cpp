#include<iostream>
using namespace std;

int maxx(int n1,int n2)
{
	int y=0;
    if(n1 >= n2 )
    {
        y=n1;
    }
    else
    {
        y=n2;
    }
    
    return y;

}

int Rod(int n,int rate[]) 
{ 
   int val[n];
   val[0] = 0;
   for (int i = 1; i <= n; i++) 
   { 
      int max_val = 0; 
      for (int j = 1; j < i; j++)
         max_val = maxx(max_val, val[i-j-1]+rate[j]);
      val[i] = max_val; 
   } 
   return val[n]; 
}
int main()
{
	int x;
	cout<<"Enter Rod Length: ";
	cin>>x;
	int rate[x];

	cout << "Enter Rates at Each Value " << endl;
	for (int i =0; i < x-1; i++) {
		cout << "Enter Rate At " << i+1 << " : ";
		cin >> rate[i];
	}
    cout<<"Maximum Profit: "<<Rod(x,rate)<<endl;
}
//Time Complexity= O(N**2)
