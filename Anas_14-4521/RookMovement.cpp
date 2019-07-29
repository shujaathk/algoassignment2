//
//  main.cpp
//  rookMovement
//
//  Created by Anas Sheikh on 29/07/2019.
//  Copyright © 2019 Anas Sheikh. All rights reserved.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

int rook(int n)
{
    int count;
    int board[n][n];
    int i,j;
   if(i==n && j==n)
       return count;
   
    for(i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i<j){
                
            
                board[i][j]=board[i+1][j];
                count++;
            }
            else if (i==j)
            {
                board[i][j]=board[i][j+1];
                count++;
            }
        }
    return count;
}

int main(int argc, const char * argv[]) {
    int n = rook(8);
    printf("%d", n);
    return 0;
}
