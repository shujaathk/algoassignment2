#Q2
starting= time.time() 
    
def wire_cut(rates, wire_len):
    profit_percentage = []
    sizes=[]
    expected_result=0
    
    for i in range(0, len(rates)):
        profit_percentage.append((rates[i]*1.0)/(i+1))
    
    
    while (True):
        index=0
        
        for i in range(0,len(rates)):
            if profit_percentage[index]<=profit_percentage[i]:
                index=i
        
        if wire_len==0:
            break
        
        if (index+1<=wire_len):
            expected_result+=rates[index]
            sizes.append(index+1)
            wire_len-=(index+1)
        else:
            profit_percentage[index]=-1
                   
    print ("Expected result is ", expected_result, " by cutting rod in ", sizes)
    
rates = [2,5,7,8,10]
length = 6

wire_cut(rates, length)
print(time.time()-starting)
