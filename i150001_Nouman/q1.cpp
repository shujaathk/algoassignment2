/*
    Author: Nouman Arshad
    Github: @nouman0320
    License: MIT license
*/

/// O(nlogn)

#include <iostream>
using namespace std;

// Chess board size is 8x8

//Method
int next(int i, int j){
    if(i==7 || j==7)
        return 1;
    return next(i, j+1)+next(i+1, j);
}


int main(){
    cout << (next(0,0) == 3432 ? "3432: Correct" : "Exception");
}
