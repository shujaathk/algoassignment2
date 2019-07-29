#include <iostream>
#include <ctime>
//#include <Windows.h>
using namespace std;

// Calculates the maximum value from the array and checks if it occurs more than one time
int Max(double* arr, int n, bool* flag) {
	int max = 0;

	for (int i = 1; i < n; i++) {
		if (arr[max] < arr[i])	max = i;
		else if (arr[max] == arr[i])* flag = true;
	}

	return max;
}

// This function traverses the whole array of ratio and looks for the ratios matching num
// and after that it looks in the length and rate array to find the index where length is 
// minimum and rate is maximum
int MoreProfitLessLength(int* length, int* rate, double* ratio, int len, double num) {
	int index = 0;
	int maxRate = -1;
	int minLength = len;

	for (int i = 0; i < len; i++) {
		if (ratio[i] == num) {
			if (length[i]<minLength && rate[i]>maxRate) {
				minLength = length[i];
				maxRate = rate[i];
				index = i;
			}
		}
	}

	return index;
}

void Q2() {
	int n = 0;							// Given length
	int result = 0;						// Maximum rate by cutting the wire
	int count = 0;						// Cuts count
	int* length;						// Available lengths (1,2,3,....,n)
	int* rate;							// Rates of lengths
	double* ratios;						// rate/length
	int* cuts;							// Cuts which give maximum rate
	int i = 0;							// Iterator
	int remaining_cuts = 0;				// Remaining length after cutting the wire
	bool repeated_value = 0;			// Flag for checking if there are more than one value that are same


	// Take the length of wire(to cut) from the user
	cout << "Given length = ";
	cin >> n;
	cout << endl;

	remaining_cuts = n;		// making a copy of n
	repeated_value = false;

	// creating dynamic arrays based on the length of wire given by the user
	length = new int[n - 1];
	rate = new int[n - 1];
	ratios = new double[n - 1];
	cuts = new int[n];

	// Getting rate of each cut from the user
	for (i = 1; i < n; i++) {
		cout << "Length = " << i;
		length[i - 1] = i;

		cout << "\tRate = ";
		cin >> rate[i - 1];
	}

	// Calculating weights (rate / length)
	for (i = 0; i < n - 1; i++)
		ratios[i] = (rate[i] * 1.0) / length[i];

	//START TIME
	clock_t time_taken = clock();

	while (remaining_cuts > 0) {
		int cut = Max(ratios, n - 1, &repeated_value);			// This function returns the index of maximum value

		if (rate[cut] == -1 || remaining_cuts == 0) break;

		if (repeated_value == true) {
			cut = MoreProfitLessLength(length, rate, ratios, n - 1, ratios[cut]);

			if (length[cut] > remaining_cuts) {
				rate[cut] = -1;
				ratios[cut] = 0;
			}
		}

		if (length[cut] <= remaining_cuts) {
			result += rate[cut];
			remaining_cuts -= length[cut];
			cuts[count] = length[cut];
			count++;
		}
		else {
			rate[cut] = -1;
			ratios[cut] = 0;
		}
	}

	//Sleep(3000);

	//END TIME
	time_taken = clock() - time_taken;

	cout << endl;
	cout << "Expected result = " << result << " by cutting wire in pieces of sizes ";

	for (i = 0; i < count; i++) {
		cout << cuts[i] << " , ";
	}

	cout << endl;
	cout << "Running time of algorithm = " << (float)time_taken/CLOCKS_PER_SEC << " seconds" << endl << endl;

	delete[] length;
	delete[] rate;
	delete[] ratios;
	delete[] cuts;

	return;
}

int main() {

	Q2();

	return 0;
}