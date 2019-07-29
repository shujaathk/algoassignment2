/* 
 * File:   main.cpp
 * Author: azizm
 *
 * 
 */

#include <iostream>
using namespace std;
//3 5 10
void Q6()
{
    int n ;
    cout<<"Total amount = ";cin>>n;
    int size;
    cout<<"enter number of coins  = ";cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
            cout<<"Coin[ "<<i+1<<" ] = ";cin>>arr[i];
    }
    int ways[n + 1];
    for(int i = 0; i < n + 1; i++)
            ways[i] = 0;
    ways[0] = 1;
    for(int i=0;i<size;i++)
    {
    	for (int j = arr[i]; j <= n; j++)
    		ways[j] += ways[j - arr[i]];
    }

    cout<<"number of ways = "<< ways[n]<<endl;
}

int count(int coins[], int number, int change){
	if (change == 0)
		return 1;
	if (change < 0)
		return 0;
	int res = 0;	
	for (int i = 0; i < number; i++)
            res += count(coins, number, change - coins[i]);	
	return res;
}

int main(void)
{
    Q6();
	int coins[] = { 1, 2, 3 };
    int number = sizeof(coins) / sizeof(coins[0]);
    int change = 4;
    cout << "Total number of ways to get desired change is "
                    << count(coins, number, change);
    return 0;
}


