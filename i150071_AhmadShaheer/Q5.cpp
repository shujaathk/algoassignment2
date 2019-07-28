#include<iostream>
using namespace std;


public void findSubsequence(int[] arrA) {
  int[] LIS = new int[arrA.length];
  for (int i = 0; i < arrA.length; i++) {
    int max = -1;
    for (int j = 0; j < i; j++) {
      if (arrA[i] > arrA[j]) {
        if (max == -1 || max < LIS[j] + 1) {
        						max = 1 + LIS[j];
        	}
      }
    }
    if (max == -1) {
    		max = 1;
    }
    LIS[i] = max;
  }
  int result = -1;
  int index = -1;
  for (int i = 0; i < LIS.length; i++) {
    if (result < LIS[i]) {
    				result = LIS[i];
    				index = i;
  	}
  }
  String path =  arrA[index] + " ";
  int res = result-1;
  for (int i = index-1; i >= 0; i--) {
    if(LIS[i]==res){
  				path =  arrA[i] + " " + path;
  				res--;
  	}			
  }
  cout<<"Longest Increasing subsequence: "<< result;
  cout<<"Actual Elements: "<< path;		
}


int main() {
    int[] A = { 1, 12, 7, 0, 23, 11, 52, 31, 61, 69, 70, 2 };
    findSubsequence(A);
    return 0;
}
