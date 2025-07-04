#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    return 0;
}


// Problem statement 

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int i=0;
        int count=0;
        int n=arr.size();
        map<int,int>mp;
        
        for(int j=0;j<n;j++){
            mp[arr[j]]++;
            
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                mp.erase(arr[i]);
                
                i++;
            }
            
            count=count+(j-i+1);
        }
        
        return count;
    }
};