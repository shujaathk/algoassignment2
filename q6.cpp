#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int> > combinations;
vector<int> coinValues;
int change = 0;

void findWays(vector<int>& currCoins, int current, int i)
{
  int old = current;

  if(i==coinValues.size())
  {
    return;
  }

  int val = coinValues[i];

  while(current<change)
  {
    current += val;
    currCoins.push_back(val);
  }

  if(current==change)
  {
    combinations.push_back(currCoins);
  }

  while (current>old)
  {
    current -= val;
    currCoins.pop_back();

    if (current>=0)
    {
      findWays(currCoins, current, i+1);
    }
  }
}

int main()
{
  cout<<"Please enter the amount of desired change: ";
  cin>>change;

  int size = 0;
  cout<<"\nPlease enter the size of coin set: ";
  cin>>size;

  int coins[size];
  cout<<"\nPlease enter the coin values: \n";
  for(int i=0;i<size;i++)
  {
    cin>>coins[i];
    coinValues.push_back(coins[i]);
  }

  vector<int> chosenCoins;

  findWays(chosenCoins, 0, 0);

  cout<<"Total number of distinct ways: "<<combinations.size()<<endl;
  cout<<"Combinations: \n";
  for (int i=0; i<combinations.size(); i++)
  {
    for (int j=0; j<combinations[i].size(); j++)
    {
      if(j!=0)
      {
        cout<<" ";
      }
      cout<<combinations[i][j];
    }
    cout<<endl;
  }
  cout<<"\nRunning time of algorithms: O(coinSetSize*desiredChange)\n";
  return 0;
}
