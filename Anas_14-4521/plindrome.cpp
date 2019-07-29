//
//  main.cpp
//  Palindrome
//
//  Created by Anas Sheikh on 28/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.

#include <iostream>
#include<stdlib.h>
using namespace std;
int CountSpecialPalindrome(string str)
{
    int n = str.length();
    
 
    int result = 0;
    
    
    int sameChar[10] = { 0 };
    
    int i = 0;
    
   
    while (i < n) {

        int sameCharCount = 1;
        
        int j = i + 1;

        while (str[i] == str[j] && j < n)
            sameCharCount++, j++;

        result += (sameCharCount * (sameCharCount + 1) / 2);
        sameChar[i] = sameCharCount;

        i = j;
    }

    for (int j = 1; j < n; j++)
    {

        if (str[j] == str[j - 1])
            sameChar[j] = sameChar[j - 1];
        
        // case 2: odd length
        if (j > 0 && j < (n - 1) &&
            (str[j - 1] == str[j + 1] &&
             str[j] != str[j - 1]))
            result += min(sameChar[j - 1],
                          sameChar[j + 1]);
    }
    return result - n;
}

// driver program to test above fun
int main()
{
    string str = "character";
    cout << CountSpecialPalindrome(str) << endl;
    return 0;
}
