#include <bits/stdc++.h> 
using namespace std;  
  
  
void printSubStr( string str, int low, int high ) 
{ 
    for( int i = low; i <= high; ++i ) 
        cout << str[i]; 
} 
  
int MyFun(string str) 
{ 
    int n = str.size();  
    bool table[n][n]; 
	memset(table, 0, sizeof(table)); 
	
    int maxLength = 1; 
	 for (int i = 0; i < n; ++i) 
        table[i][i] = true; 

    int start = 0; 
    for (int i = 0; i < n-1; ++i) 
    { 
        if (str[i] == str[i+1]) 
        { 
            table[i][i+1] = true; 
            start = i; 
            maxLength = 2; 
        } 
    } 
    
    for (int k = 3; k <= n; ++k) 
    { 
        for (int i = 0; i < n-k+1 ; ++i) 
        { 
            int j = i + k - 1; 
            if (table[i+1][j-1] && str[i] == str[j]) 
            { 
                table[i][j] = true; 
  
                if (k > maxLength) 
                { 
                    start = i; 
                    maxLength = k; 
                } 
            } 
        } 
    } 
  
   cout << "Longest palindrome substring is: "; 
   printSubStr( str, start, start + maxLength - 1 ); 
   cout<<endl;
    return 0; 
} 
int main() 
{ 
	
    string str;
    cout<<"Enter String: ";
    cin>>str;
    MyFun( str );
    return 0; 
} 
//time Complexity= O(N**2)
