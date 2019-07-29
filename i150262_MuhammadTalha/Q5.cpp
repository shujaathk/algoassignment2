#include <iostream>
#include <ctime>

using namespace std;

void Q5() {
	int n = 0;
	int* arr;
	int* subsequence;
	int count = 0;
	int i = 0;

	cout << "Enter length of string= ";
	cin >> n;

	arr = new int[n];
	subsequence = new int[n];

	cout << "\nEnter Values of Array\n";
	
	for (i = 0; i < n; i++) {
		cout << i << ": ";
		cin >> arr[i];
	}

	cout << endl;

	//START TIME
	clock_t time_taken = clock();

	subsequence[count] = arr[0];
	count++;

	for (i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			subsequence[count] = arr[i];
			count++;
		}
	}


	//END TIME
	time_taken = clock() - time_taken;

	cout << "The length of longest nonconsecutive increasing subsequence is " << count << " and the subsequence is [";

	for (i = 0; i < count; i++) {
		cout << subsequence[i] << ", ";
	}

	cout << "]" << endl << endl;

	cout << "Running time of algorithm = " << (float)time_taken / CLOCKS_PER_SEC << " seconds" << endl;
	cout << "There is no need of dynamic programming as we are only doing n comparisons. We are starting the loop from 1 and compairing the current value with the previous one." << endl << endl;

	return;
}

int main() {
	Q5();

	return 0;
}