#include <iostream>
#include <ctime>

using namespace std;

int* arr;

void MissingNumber(int start, int end, int n) {
	if (end > start) {
		if (start == arr[n])
			MissingNumber(start + 1, end, n + 1);
		else
			cout << "The missing number in the array is " << start << endl;
	}
}

void Q4() {
	int n = 0;
	int i = 0;
	int num = 0;

	cout << "Enter length of string = ";
	cin >> n;

	arr = new int[n];
	
	cout << "\nEnter Values of Array(In ascending order)\n";

	for (i = 0; i < n; i++) {
		cout << i << ": ";
		cin >> arr[i];
	}

	cout << endl;

	//START TIME
	clock_t time_taken = clock();

	int start = arr[0];
	int end = arr[n - 1];
	MissingNumber(start, end, 0);

	//END TIME
	time_taken = clock() - time_taken;

	cout << "Running time of algorithm = " << (float)time_taken / CLOCKS_PER_SEC << " seconds" << endl;

	return;
}

int main() {
	Q4();

	return 0;
}