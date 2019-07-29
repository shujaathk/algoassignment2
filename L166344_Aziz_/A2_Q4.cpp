#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>
#include<set>
using namespace std;

/*
 * 
 */
//time Complexity O(log n)


int Q4(int arr[], int size) 
{
  int left , right ,mid;
    left = 0, right =size -1;
    for (;left <= right;)
    {
        mid = (left+right)/2;
        if(arr[mid]!=mid+1)
        {
          if(arr[mid-1]==mid)
            return mid+1;
        }
        if(arr[mid]==mid+1)
            left=mid+1;
        else if (arr[mid]>mid+1)
            right = mid-1;
        
    }
    return -1;
}
int main() {
    //......Q4............
    int x[10]={2,3,4,5,6,7,8,9,10,11};
    cout<<Q4(x,10);
    //....................
   
    
        
    return 0;
}