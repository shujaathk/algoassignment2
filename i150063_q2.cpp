#include<iostream>
using namespace std;

void cutWire(int[], int);

int main()
{
	int price [] = { 2, 5, 7, 8, 10};
	int n = 6;

	cutWire(price, n);
	return 0;
}

void cutWire(int rate[], int n)
{
  int totalWires;
  int wires[n+1];
  int val[n+1];
  int lastWire[n+1];
  val[0] = 0;
  int i, j;

  for (i = 1; i<=n; i++)
  {
    int max_val = -1;
    int best_wire_len = -1;

    for (j = 0; j < i; j++)
    {
      if(max_val <rate[j] + val[i-j-1])
      {
        max_val = rate[j] + val[i-j-1];
        best_wire_len = j;
      }
    }

    val[i] = max_val;
    lastWire[i] = best_wire_len + 1;
  }

  for (i = n, j = 0; i>0; i -= lastWire[i])
  {
    wires[j++] = lastWire[i];
  }
  totalWires = j;

  cout<<endl<< "Maximum value is : "<<val[n];
  cout<<" by cutting wire in pieces of Lengths: ";
  for(int i=0;i<totalWires;i++)
  {
    cout<<wires[i];
    if(i<totalWires-1)
    	cout<<",";
  }
  cout<<endl<<"Running time of Algorithm: O(n^2)"<<endl;
}


