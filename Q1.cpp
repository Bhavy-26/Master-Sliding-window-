#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int i=0,j=0;
        int n=arr.size();
        int sum=0;
        int mx=INT_MIN;
        while(j<n){
            
            sum=sum+arr[j];
            
            if( j-i+1 <k)
            j++;
            else if(j-i+1==k){
                mx=max(sum,mx);
                sum=sum-arr[i];
                i++;
                j++;
            }
            
        }
        
        return mx;
    }
};


// link to question https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/0