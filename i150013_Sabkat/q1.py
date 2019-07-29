#Q1
#import time
starting= time.time()

arr=[[0 for x in range(8)] for y in range(8)]

i=7
while(i>=0):
    for j in range(0,8):
        if(j==0):
            arr[i][j]=1
        elif(i==7):
            arr[i][j]=1
        elif(i>=0 and j<=8):
            arr[i][j]=arr[i+1][j]+arr[i][j-1]
          
          
    i-=1
    
i=7
while(i>=0):
    for j in range(0,8):
        print(arr[i][j], end=" ")
    print("\n")
    i-=1
print(time.time()-starting)    
    
