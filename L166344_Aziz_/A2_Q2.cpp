/* 
 * File:   main.cpp
 * Author: azizm
 *
 * 
 */
 //Time Complexity O(n^2)

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void Q2()
{
	int maxlen = 5;
	cout<<"Length of rod = ";cin>>maxlen;
	int length[maxlen];
	int rate[maxlen];
	for(int i =0;i<maxlen;i++)
		length[i]=i+1;
	cout<<"Enter rate :"<<endl;
	for(int i=0;i<maxlen;i++)
	{
		cout<<"Length = "<<i+1<<", Rate = ";cin>>rate[i];
	}
	int size = sizeof(length)/sizeof(length[0]);
	int temp1[maxlen+1];
	int temp2[maxlen+1];
	temp1[0] = 0;
	temp2[0] = -1;
	for(int i=1;i<=maxlen;i++)
	{
		temp2[i] = temp2[i-1];
		int max = temp1[i-1];
		for(int j=0;j<size;j++)
		{
			int prev = i-length[j];
			if(prev >= 0 && (temp1[prev] + rate[j]) > max)
			{
				max = temp1[prev] + rate[j];
				temp2[i]= j;
			}
			temp1[i] = max;
      }
   }
   cout<<"Maximum rate = "<<temp1[maxlen]<<endl;

   int k = maxlen;
   int instances[size];
   for(int i=0;i<size;i++)
	   instances[i] = 0;
   while(k >= 0)
   {
	   int x = temp2[k];
       if(x == -1)
    	   break;
       instances[x] += 1;
       k -= length[temp2[k]];
   }
   cout<<"pieces = [ ";
   for(int i=0;i<size;i++)
   {
	   for(int j=0;j<instances[i];j++)
		   cout<<length[i]<<" ";
   }
   cout<<"]"<<endl;
}


int main() {

   Q2();
   return 0;
}


