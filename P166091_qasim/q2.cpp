// A Dynamic Programming solution for cut wire problem 
#include<stdio.h> 
#include<limits.h> 

// A utility function to get the maximum of two integers 
int max(int a, int b) { return (a > b)? a : b;} 

//cutrod funtion starts here
int cutwire(int price[], int n) 
{ 
int val[n+1]; 
val[0] = 0; 
int i, j; 

for (i = 1; i<=n; i++) 
{ 
	int max_val = INT_MIN; 
	for (j = 0; j < i; j++) 
		max_val = max(max_val, price[j] + val[i-j-1]); 
	val[i] = max_val; 
} 

return val[n]; 
} 
//main funtion
int main() 
{ 
	int arr[] = {1, 5, 8}; 
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("Maximum Obtainable Value is %d", cutwire(arr, size)); 
	getchar(); 
	return 0; 
//time complexity O(n^2)
}
