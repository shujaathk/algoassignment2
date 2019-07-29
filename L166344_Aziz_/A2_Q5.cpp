/* 
 * File:   main.cpp
 * Author: azizm
 *
 * 
 */

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
//Time Complexity O(n^2)
//or 3



void Q5( int arr[], int n )
{
    int vector[n];vector[0] = 1;
    int dum1[n],dum2[n];
    int i = 1;
    while ( i < n  )
    {
        vector[i] = 1;
        int j = 0;
        while ( j < i )
        {
            if ( arr[i] > arr[j] && vector[i] < vector[j] + 1)
            {
                    vector[i] = vector[j] + 1;
                    dum1[j]=1;
            }
            
            j++;
            //dum1[j]=1;
            if(j==i)
            {
                dum1[j]=1;
                if(vector[i]>vector[i-1])
                {
                    for(int i =0 ; i<n;i++)
                    {
                        //if(j!=i)
                        {
                        dum2[i]=dum1[i];
                        dum1[i]=0;
                        }
                    }
                }
            }
        }
        i++;
    }
    cout<<"Length longest non consecutive increasing subsequence = "<<*max_element(vector, vector+n)<<endl;
    for(int i = 0 ; i<n ;i++)
    {
        //cout<<dum2[i]<<"    ";
        if(dum2[i]==1)
            cout<<arr[i]<<" ";
    }
}

int main() {
    
    int arr[] = { 1,5,6,4,7,3,2,4,8,9 };
    Q5( arr, sizeof(arr)/sizeof(arr[0]));    
    return 0;
}

