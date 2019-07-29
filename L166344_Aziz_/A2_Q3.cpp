/* 
 * File:   main.cpp
 * Author: azizm
 *
 * 
 */

#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 
  
//Time Complexity O(n^2)


void reverseStr(string& str,int n) 
{  
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 

string longest_Palindrome(string &array,int size) 
{ 
    
    string rev_array = array; 
    reverseStr(rev_array,size);
  
    int dp_Array[size+1][size+1];
    
    for (int i=0; i<=size; i++) 
    { 
        for (int j=0; j<=size; j++) 
        { 
            if (i == 0 || j == 0) 
                dp_Array[i][j] = 0; 
            else if (array[i-1] == rev_array[j-1]) 
                dp_Array[i][j] = dp_Array[i-1][j-1] + 1; 
            else
                dp_Array[i][j] = max(dp_Array[i-1][j], dp_Array[i][j-1]); 
        } 
    } 
    
    int index = dp_Array[size][size];
    
    
    string lcs(index+1, '\0');
    
    int i = size, j = size; 
    while (i > 0 && j > 0) 
    { 
        
        if (array[i-1] == rev_array[j-1]){
            lcs[index-1] = array[i-1]; 
            i--; 
            j--; 
  
            index--; 
        } 
        else if (dp_Array[i-1][j] > dp_Array[i][j-1]) 
            i--; 
        else
            j--; 
    } 
    
     
    return lcs;
   
    
     
} 
  
int main() 
{ 
    string str = "character"; 
    cout << longest_Palindrome(str,9); 
    return 0; 
} 


