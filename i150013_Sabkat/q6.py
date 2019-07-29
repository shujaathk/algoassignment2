#q6
def count( S, m, n ): 
    table=[[0 for x in range(m+1)] for x in range(n+1)] 
    for i in range(1,m):
        table[0][i] = 1; 
 

    for i in range(1,m): 
        for j in range(1,n): 
            if(S[i-1]>j): 
                table[i][j]=table[i-1][j] 
            else:
                 table[i][j]=table[i-1][j]+table[i][j-(i-1)]
    for i in range(1,m): 
        for j in range(1,n):
            print(table[i][j],end=" ")
        print("\n")
    return table[m-1][n-1] 
 
arr = [1, 2, 3] 
m = len(arr) 
N = 4
x = count(arr, m, N) 
print (x) 
