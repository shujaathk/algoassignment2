/*
    Author: Nouman Arshad
    Github: @nouman0320
    License: MIT license
*/


/// O(n^2)

#include <iostream>
#include <string>

using namespace std;

int rodCut(int price[], int n)
{
	int T[n + 1];
	// initialize maximum profit to 0
	for (int i = 0; i <= n; i++)
		T[i] = 0;
	// consider rod of length i
	for (int i = 1; i <= n; i++)
	{
		// divide the rod of length i into two rods of length j
		// and i-j each and take maximum
		for (int j = 1; j <= i; j++)
			T[i] = max(T[i], price[j - 1] + T[i - j]);
	}
	// T[n] stores maximum profit achieved from rod of length n
	return T[n];
}

// main function
int main()
{
	int price [] = { 2, 5, 7, 8, 10};
	// rod length
	int n = 6;
	cout << "Maximum profit " << rodCut(price, n);

	return 0;
}
