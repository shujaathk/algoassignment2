//
//  main.cpp
//  LongestCommonSubsequence
//
//  Created by Anas Sheikh on 28/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.
//

/* Dynamic Programming C++ implementation of temp problem */
#include<iostream>
#include<stdio.h>
using namespace std;

int MAXIMUMFIND( int arr[], int n )
{
    int temp[n];
    
    temp[0] = 1;
    for (int i = 1; i < n; i++ )
    {
        temp[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && temp[i] < temp[j] + 1)
            {
                temp[i] = temp[j] + 1;
               printf("%d \n",arr[i] );
                
            }
        //printf("%d ", arr[i]);
    }
    
    // Return maximum value in temp[]
    return *max_element(temp, temp+n);
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of temp is %d\n", MAXIMUMFIND(arr,n));
    return 0;
}
/* Time complexity of above program using Dynamic Programming is O(n^2). We can devise the solution with complexity of O(N LOG N) but the code for that matter is way more complex.
*/
