#include <iostream> 
#include <cstdlib>
#include <time.h>
using namespace std;
int MyFun(int ar[], int N);
int main() 
{ 
	
	/*int N,r,y;
	cout<<"Enter Array Size: ";
	cin>>N;
	y=N-2;
	int *arrr;
	arrr=new int[N];
	srand (time(NULL));
	r= (rand() % y)+3;
	for(int i=0;i<N;i++)
	{
		if(i>=r)
		{
			arrr[i]=i+1;
		}
		else
		{
			arrr[i]=i;
		}
		
	}
	
	cout<<endl;
	cout<<"S: "<<N<<endl;
    cout <<"Missing Value:"<< MyFun(arrr, N); 
    */
    
    cout<<endl;
    int arr[] = {1, 2, 3, 5, 6, 7, 8}; 
    int N = sizeof(arr)/sizeof(arr[0]);
    cout <<"Missing Value:"<< MyFun(arr, N)<<endl; 
    return 0;
} 


int MyFun(int ar[], int N) 
{ 
    int l = 0, r = N - 1; 
    while (l <= r) { 
	int mid = (l + r) / 2;  
        if (ar[mid] != mid + 1 &&  
                        ar[mid - 1] == mid) 
            return mid + 1; 
        if (ar[mid] != mid + 1) 
            r = mid - 1;  
        else
            l = mid + 1; 
    } 

    return -1; 
} 
//time Complexity= O(logN)
