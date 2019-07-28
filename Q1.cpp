// Time complexity of the algorithm is O(nlogn)

#include <iostream>
using namespace std;

int exploreChess(int i, int j){
    if(i==7 || j==7)
        return 1;
    return next(i, j+1)+next(i+1, j);
}


int main(){
    cout<<exploreChess(0,0);
}