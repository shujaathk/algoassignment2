// Time complexity of the algorithm is O(n^2)

#include<stdio.h> 
#include<string.h> 
  

int maximum(int x, int y){
	if(x > y){
		return x;
	else
		return y;
} 
  

int LPS(char *str);
  
int main() 
{ 
    char seq[] = "GEEKS FOR GEEKS"; 
    int n = strlen(seq); 
    printf ("The length of the LPS is %d", LPS(seq)); 
    getchar(); 
    return 0; 
}

int LPS(char *str) 
{ 
   int n = strlen(str); 
   int i, j, k; 
   int L[n][n]; 
   for (i = 0; i < n; i++){ 
      L[i][i] = 1;
    }
    for (k=2; k<=n; k++){ 
        for (i=0; i<n-k+1; i++){ 
            j = i+k-1; 
            if (str[i] == str[j] && k == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = maximum(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 