#Q5
starting= time.time()
arr = [2, 5, 6, 3,4,7, 8, 9]
arr2=[0]
j=0
arr2[0]=arr[0]
for i in range(1,len(arr)):
    
    if(arr[i]>arr2[j]):
        #print(arr[i])
        arr2.append(arr[i])
        j=j+1    

for j in range(len(arr2)):
    print(arr2[j])
print(time.time()-starting)    
