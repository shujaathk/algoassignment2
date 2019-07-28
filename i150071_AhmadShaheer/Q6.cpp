#include <iostream>
using namespace std;

int totalWays(int S[], int n, int N);

int main()
{
	int S[] = { 1, 2, 3 };
	int n = sizeof(S) / sizeof(S[0]);
	int N = 4;
	cout << "Total number of ways to get desired change is "
			<< totalWays(S, n, N);
	return 0;
}

int totalWays(int S[], int n, int N)
{
	if (N == 0)
		return 1;

	if (N < 0)
		return 0;

	
	int res = 0, i=0;
	while(i < n)
	{
		res += totalWays(S, n, N - S[i]);
		i++;
	}

	return res;
}