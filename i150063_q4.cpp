#include <iostream>
#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main()
{
	int arr[] = {1,2,3,5,6,7,8,9};
	int N = 9;
	

	ll Sum =N*(N+1);
	Sum = Sum>>1;  //if all numbers are present then the sum is N*(N+1)/2
	ll sum = 0;
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	 	sum += arr[i]; //sum of elements actually present in the array

	cout <<"Missing number is "<<Sum-sum <<endl;

	return 0;
}
