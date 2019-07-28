/*
    Author: Nouman Arshad
    Github: @nouman0320
    License: MIT license
*/

/// O(n^2)

#include<iostream>
#include<string>
#include<algorithm>

#define n 30

using namespace std;

int memoTable[n][n];

string findPalindrome(string str, string strReverse, int str_len, int strReverse_len)
{
  if(str_len == 0 || strReverse_len == 0)
  {
    return string("");
  }

  if(str[str_len-1] == strReverse[strReverse_len-1])
  {
    return findPalindrome(str, strReverse, str_len-1, strReverse_len-1) + str[str_len-1];
  }

  if(memoTable[str_len-1][strReverse_len]>memoTable[str_len][strReverse_len-1])
  {
    return findPalindrome(str, strReverse, str_len-1, strReverse_len);
  }

  return findPalindrome(str, strReverse, str_len, strReverse_len-1);
}

int main()
{
  string str;

  str = "character";

  int str_len = str.length();

  string strReverse = str;
  reverse(strReverse.begin(), strReverse.end());

  for(int i=0;i<=str_len;i++)
  {
    for(int j=0;j<=str_len;j++)
    {
      if(i==0 || j==0)
      {
        memoTable[i][j] = 0;
      }
      if(str[i-1]==strReverse[j-1])
      {
        memoTable[i][j] = memoTable[i-1][j-1] + 1;
      }
      else
      {
        memoTable[i][j] = max(memoTable[i-1][j], memoTable[i][j-1]);
      }
    }
  }

  string longestPalindrome = findPalindrome(str, strReverse, str_len, str_len);
  cout<<"Longest Palindrome Subsequence: "<<longestPalindrome<<endl;
}
