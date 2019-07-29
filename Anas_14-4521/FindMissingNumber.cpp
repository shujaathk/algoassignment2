//
//  main.cpp
//  FindingMissingNumber
//
//  Created by Anas Sheikh on 28/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.
#include <iostream>
#include <array>
using namespace std;

int search(int array[], int size)
{
    int a = 0, b = size - 1;
    int mid;
    while ((b - a) > 1) {
        mid = (a + b) / 2;
        if ((array[a] - a) != (array[mid] - mid))
            b = mid;
        else if ((array[b] - b) != (array[mid] - mid))
            a = mid;
    }
    return (array[mid] + 1);
}

int main()
{
    int array[] = { 1,2,3,5,6,7,8 };
    int size = sizeof(array) / sizeof(array[0]);
    
    cout << "Missing number:" << search(array, size)<<"\n";
}

/* n binary search, the concept behind this solution is that the elements appearing before the missing element will have array[i] – i = 1 and those appearing after the missing element will have array[i] – i = 2. Time Complexity of the following algorithm is O(logn);
 */
 
