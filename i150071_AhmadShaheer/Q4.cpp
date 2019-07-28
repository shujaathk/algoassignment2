#include <iostream> 
using namespace std; 
  
int search(int ar[], int size);
  
int main() 
{ 
    int array[] = { 1, 2, 3, 4, 5, 6, 8 }; 
    int size = sizeof(array) / sizeof(array[0]); 
    cout << "Missing number:" << search(array, size); 
} 

int search(int ar[], int size) 
{ 
    int a = 0, b = size - 1; 
    int mid; 
    while ((b - a) > 1) { 
        mid = (a + b) / 2; 
        if ((ar[a] - a) != (ar[mid] - mid)) 
            b = mid; 
        else if ((ar[b] - b) != (ar[mid] - mid)) 
            a = mid; 
    } 
    return (ar[mid] + 1); 
} 