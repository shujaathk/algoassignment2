#include <iostream>
using namespace std;

void findNumber(int arr[], int size)
{
  int missingNumber = 0;
  int first = 0;
  int last = size - 1;
  int middle = 0;
  int arrFirst = 0;
  int arrMiddle = 0;
  int arrLast = 0;

  while ((last - first) > 1)
  {
    middle = (first + last) / 2;

    arrFirst = arr[first] - first;
    arrMiddle = arr[middle] - middle;
    arrLast = arr[last] - last;

    if (arrFirst != arrMiddle)
    {
      last = middle;
    }
    else if (arrLast != arrMiddle)
    {
      first = middle;
    }
  }

  missingNumber = (arr[middle]+1);
  cout<<"\nMissing Number in the sorted array: "<<missingNumber<<endl;
  cout<<"Running time of the Algorithm: O(n)"<<endl;
}

int main()
{
  int size = 0;

  cout<<"Please enter the size of the array: ";
  cin>>size;

  int arr[size];

  cout<<"\nPlease enter the values for the sorted array: "<<endl;
  for(int i=0; i<size; i++)
  {
    cin>>arr[i];
  }

  cout<<"\nSorted Array: "<<endl;
  for(int i=0; i<size; i++)
  {
    cout<<arr[i]<<endl;
  }

  findNumber(arr, size);

  return 0;
}
