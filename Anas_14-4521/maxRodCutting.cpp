//
//  main.cpp
//  maxRodCutting
//
//  Created by Anas Sheikh on 28/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.

#include<stdio.h>

int max(int a, int b) {
    if(a>b)
        return a;
    else
        return b;
}

// n = length of rod
int maxRodCutting(int price[], int n)
{
    int val[n+1];
    val[0] = 0;
    int i, j;

    for (i = 1; i<=n; i++)
    {
        int mvalue = 0;
        for (j = 0; j < i; j++)
            mvalue = max(mvalue, price[j] + val[i-j-1]);
        val[i] = mvalue;
    }
    
    return val[n];
}
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Value is %dn \n", maxRodCutting(arr, size));
    
    return 0;
}
/* Time complexity of this algorithm is is O(n^2) which is much better than the naive recursive algorithm. This problem follows both the rules of Dynamic programming which is optimal substructure and overlapping problems */
