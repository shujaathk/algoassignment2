#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define N 25
int lookup[N][N];

string longestPalindrome(string X, string Y, int m, int n)
{
	if (m == 0 || n == 0)
		return string("");

	if (X[m - 1] == Y[n - 1])
	{
		return longestPalindrome(X, Y, m - 1, n - 1) + X[m - 1];
	}


	if (lookup[m - 1][n] > lookup[m][n - 1])
		return longestPalindrome(X, Y, m - 1, n);

	return longestPalindrome(X, Y, m, n - 1);
}

int LCSLength(string X, string Y, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (X[i - 1] == Y[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1] + 1;

			else
				lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
		}
	}
	return lookup[n][n];
}

int main()
{
	string X = "character";
	int m = X.length();

	string Y = X;
	reverse(Y.begin(), Y.end());

	cout << "The length of Longest Palindromic Subsequence is "
			<< LCSLength(X, Y, m) << '\n';

	cout << "The Longest Palindromic Subsequence is "
			<< longestPalindrome(X, Y, m, m);

	return 0;
}