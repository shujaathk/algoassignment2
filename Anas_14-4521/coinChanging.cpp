//
//  main.cpp
//  CoinChangingProblem
//
//  Created by Anas Sheikh on 28/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.
//

// Recursive C program for
// coin change problem.
#include<stdio.h>

int CoinChange( int S[], int m, int n )
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;
    

    if (m <=0 && n >= 1)
        return 0;

    return CoinChange( S, m - 1, n ) + CoinChange( S, m, n-S[m-1] );
}

// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("Total Different ways for Coin change: %d \n", CoinChange(arr, m, 6));
    
    return 0;
}
/* Time complexity of the following program is O(n). I think so */
