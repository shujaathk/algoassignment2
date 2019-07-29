#include <iostream>
using namespace std;
void chess(int board[][4],int i,int j);
int noOfPaths=0;
int main()
{
	int board[4][4] = { {0,1,1,1},
						{1,1,1,1},
						{1,1,1,1},
						{1,1,1,2},};
	chess(board,0,0);
	cout<<"NO OF PATHS :"<<noOfPaths<<endl;
    return 0;
}
void chess(int board[][4], int i, int j) {
	if(board[i][j]==2){
		++noOfPaths;
	}
	if (i < 4 && j < 4) {
		 chess(board, i + 1, j) ;
		 chess(board, i, j + 1) ;
	}
}


