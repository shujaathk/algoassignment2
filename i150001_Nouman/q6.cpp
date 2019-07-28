/*
    Author: Nouman Arshad
    Github: @nouman0320
    License: MIT license
*/

/// O(N*x)

#include<iostream>

using namespace std;

int coinChange(int coin[], int x, int N)
{
    int i,j;

    //make a matrix of size (N+1)*x to tabulate the computed values
    int dp[N+1][x];

    //dp[i][j] represents no.of ways in which change of Rs. i can be made with just j type of coins available

    int including,excluding;

    //initialization
    //since, there is only one way in which change of Rs. 0 can be made ie., not including any coin
    for(j=0;j<x;j++)
    {
        dp[0][j]=1;
    }

    //i represents the amount whose change is required
    for(i=1;i<=N;i++)
    {
        //j represents the coin values available
        for(j=0;j<x;j++)
        {
            //if the the value of current coin is less than or equal to total amount whose change is required
            //include this coin
            if(i>=coin[j])
            {
                including=dp[i-coin[j]][j];
            }

            else
                including=0;

            //excluding will store the number of ways in which the amount can be changed without including the current coin value
            if(j>=1)
                excluding=dp[i][j-1];

            else
                excluding=0;

            //dp[i][j] will be the sum of no.of ways by including as well as excluding the current coin
            dp[i][j]=including+excluding;
        }
    }

    return dp[N][x-1];
}

int main()
{
    int i;
    int x = 4;  //number of distinct values of coins
    int N = 9;  //amount whose change is required


    //distinct values of coins
    int coin[x] = {1, 3, 5, 7};



    cout<<"No. of ways in which Rs."<<N<<" can be changed is ";
    cout<<coinChange(coin,x,N);

    cout<<endl;
    return 0;
}
