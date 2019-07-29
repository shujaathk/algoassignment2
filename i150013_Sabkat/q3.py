#Q3
def pal(str): 
    n = len(str) 

    arr = [[0 for x in range(n)] for x in range(n)] 
    for i in range(n): 
        arr[i][i] = 1


    for cl in range(2, n+1): 
        for i in range(n-cl+1): 
            j = i+cl-1
            if str[i] == str[j]: 
                arr[i][j] = arr[i+1][j-1] + 2
            elif str[i] == str[j] and cl == 2: 
                arr[i][j] = 2
            else: 
                arr[i][j] = max(arr[i][j-1], arr[i+1][j]); 
    return arr[0][n-1] 

sequence = "racecar"
print("The length of the least sequence is " + str(pal(sequence))) 


