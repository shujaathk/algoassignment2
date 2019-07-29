#include <iostream> 
using namespace std;
int MyFun(int *p, int s)
{
    int min = p[0];

    for (int i = 0; i < s; i++)

    {

        if (min > p[i])

            min = p[i];

    }
    int x=min;
    for(int i=0;i<s;i++)
    {
    	if(p[i]>=x)
    	{
    		cout<<p[i]<<" ";
    		x=p[i];
		}
	}
	cout<<endl;
    return 0;
}
int main() 
{
	int n;
	cout<<"Enter Array size: ";
	cin >> n;
	int *array = new int[n];
	cout<<"Enter Values: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	MyFun(array,n);
return 0;
} 
//time Complexity= O(N)
