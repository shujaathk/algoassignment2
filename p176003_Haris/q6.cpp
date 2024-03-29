#include <iostream>
using namespace std;


int count(int S[], int n, int N)
{
	
	if (N == 0)
		return 1;

	
	if (N < 0)
		return 0;

	
	int res = 0;

	// do for each coin
	for (int i = 0; i < n; i++)
	{
		
		res += count(S, n, N - S[i]);
	}

	
	return res;
}


int main()
{
	
	int S[] = { 1, 2, 3 };
	int n = sizeof(S) / sizeof(S[0]);

	
	int N = 4;

	cout << "Total number of ways to get desired change is "
			<< count(S, n, N);

	return 0;
}