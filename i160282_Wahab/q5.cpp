#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	int A[] = {1,5,6,4,7,3,2,4,8,9};
	int M[]={0,0,0,0,0,0,0,0,0,0};
	M[0]=A[0];
	int j=1;
	for(int i=1;i<10;++i){
		if(M[j-1]<A[i]){
			M[j]=A[i];
			++j;
		}
	}
	for(int i=0;i<10;++i){
			cout<<M[i]<<",";
		}

	return 0;
}
//O(N)
//BECAUSE THERE ARE NO OVERLAPPING SUBPROBLEMS
