// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
////////Q4//////////////////
int  find(int *ar, int size)

{
	int y = size - 1;

	int x = 0;
	int half;
	while ((y - x)>1)
	{
		half = (x + y) / 2;
		//cout << half << endl;
		if ((ar[x] - x) != (ar[half] - half))
			y = half;
		else if ((ar[y] - y) != (ar[half] - half))
			x = half;
	}

	return (ar[half] + 1);
	//O(n)
}
/////////Q2////////////////
//It will take the string and prints the longest palindromic substring
//and its length 
void palindrome(char *arr)
{
	int max = 1; 
	int begin = 0;
	int n = strlen(arr);
	int l;
	int h;	
	// considering every value as centre pnt 1 by 1
	for (int i = 1; i < n; ++i)
	{
		h =i++;
		// biggest odd paldrm with centre i//
		l = i--;
		
		while ((h < n)&&(l >= 0)&& arr[l] == arr[h])
		{
			if ((h - l + 1)> max)
			{
				begin = l;
				max = h - l + 1;
			}
			--l;
			++h;
		}
		l = i - 1;
		h = i;
		while (l >= 0 && h < n && arr[l] == arr[h])
		{
			if (h - l + 1 > max)
			{
				begin = l;
				max = h - l + 1;
			}
			--l;
			++h;
		}
	}
	int end = begin + max - 1;
	cout << "plndm is: ";
	for (int i = begin; i <= end; ++i)
	{
		cout << arr[i]; // lngst plndrm seq
	}


//O(n^2)
}
/////////Q6/////////////

int comb(int S[], int m, int n)
{
	// 1 solution	
	if (n == 0)
		return 1;
	//no sol 
	if (n < 0)
		return 0;

	// solution exist 
	if (m <= 0 && n >= 1)
		return 0;
	return comb(S, m - 1, n) + comb(S, m, n - S[m - 1]);
}
////////////////Q5///////////////////
int LNS(int s[], int size,int value,int init) {
	if (size == 0 ) {
		return 0;
	}
	//size is the size of array s,value is the length of the selected seq, init is the started initial starting pnt array 
	else {
		if (s[init] > value) {
			value++;
			cout << s[init];
		 }
		return value + LNS(s, size--,value,init++);
	}
	
// O(n) 
}
int main()
{


		// q6
		//int i, j;
		//int arry[] = { 1, 2, 3 };
		//int m = sizeof(arry) / sizeof(arry[0]);
		//cout<< comb(arry, m, 4);
	
	///////q3///////////
	char s[] = "hello";
	palindrome(s);
	return 0;
	/////////Q4///////////
	//int list[] = { 1, 2, 3, 4 };
	//int s=0;
	//s=sizeof(list) / sizeof(list[0]);
	//cout << "Missing number:" << find(list,s);
	////////////////////////////
}
