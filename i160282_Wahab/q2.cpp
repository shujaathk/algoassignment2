#include <iostream>
using namespace std;

int Wire(int rate[], int n)
{
	int * array = new int[n + 1];
	array[0] = 0;


	for (int i = 1; i <= n; i++)
	{
		int maxi = -99999;
		for (int j = 0; j < i; j++)
		{
			maxi = max(maxi, array[i - j - 1]+ rate[j]);
		}
		array[i] = maxi;
	}

	return array[n];
}



int main()
{

	int n1;
	cout << "Enter Size of array: ";
	cin >> n1;

	int * input = new int[n1+1];

	cout << "Enter the Rates " << endl;
	for (int i =0; i < n1; i++) {
		cout << "Enter Rate " << i << " : ";
		cin >> input[i];
	}

	int a= Wire(input, n1);
	cout << "Expected Result="<< a;
	return 0;
}
