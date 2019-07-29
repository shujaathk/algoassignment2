#include <iostream>
#include <ctime>

using namespace std;


void Q1() {
	int chess_board[8][8] = { 0 };
	int len = 8;

	//START TIME
	clock_t time_taken = clock();

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (i == 0 || j == 0) {
				chess_board[i][j] = 1;
			}
			else {
				chess_board[i][j] = chess_board[i - 1][j] + chess_board[i][j - 1];
			}
		}
	}


	//END TIME
	time_taken = clock() - time_taken;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cout << chess_board[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "\nThere are " << chess_board[len - 1][len - 1] << " paths to move from one corner to diagonally opposite corner" << endl;
	cout << "Running time of algorithm = " << (float)time_taken / CLOCKS_PER_SEC << " seconds" << endl << endl;

	return;
}

int main() {
	Q1();

	return 0;
}
