#include<iostream>
using namespace std;

void cutWire(int rate[], int n)
{
  int numWiresUsed;
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
  numWiresUsed = j;

  cout<<"\nMaximum Obtainable Value is: "<<val[n];
  cout<<" by cutting wire in pieces of Lengths: ";
  for(int i=0;i<numWiresUsed;i++)
  {
    cout<<wires[i]<<" ";
  }
  cout<<"\nRunning time of Algorithm: O(n^2)\n";
}

int main()
{
  int n = 0;

  cout<<"\nPlease enter the length of the wire: ";
  cin>>n;

  int marketRates[n];

  cout<<"\nPlease enter the market rate for the lengths of the wire: \n";
  for(int i=0;i<n;i++)
  {
    cout<<"Length "<<i+1<<" Rate = ";
    cin>>marketRates[i];
  }

  cutWire(marketRates, n);
  return 0;
}
