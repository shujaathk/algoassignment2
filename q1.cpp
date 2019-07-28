#include<iostream>
using namespace std;

void countPaths(int n)
{
  int board[n][n];
  for(int i=0;i<n;i++)
  {
    board[i][0] = 1;
    board[0][i] = 1;
  }

  for(int i=1;i<n;i++)
  {
    for(int j=1;j<n;j++)
    {
      board[i][j] = board[i-1][j] + board[i][j-1];
    }
  }

  cout<<"\nTotal number of shortest paths: "<<board[n-1][n-1];
  cout<<"\nRunning time of the algorithm: O(n^2)"<<endl;
}

int main()
{
  countPaths(8);
  return 0;
}
