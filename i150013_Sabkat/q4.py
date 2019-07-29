#Q4
import time
starting= time.time()
arr=[-3,-1,0,1,2,3,4,5,7,8,9]
left=arr[0]
i=0;
right=arr[len(arr)-1]
def recur(arr,left,right,i):
    if(right > left):
        if(left==arr[i]and left<right):
            #print(left)
            #left=arr[left+1]
            recur(arr,left+1,right,i+1)
        elif(left!=arr[i]):
            print("Missing element")
            print(left)
        else:
            print("no missing element")
recur(arr,left,right,i)            
print(time.time()-starting)
