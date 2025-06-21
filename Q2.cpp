#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int>ans;
        int i=0,j=0;
        int n=arr.size();
        queue<int>q;  // to store negative number whenever I see while incrementing j
        
        while(j<n){
            
            if(arr[j]<0)
            q.push(arr[j]);
            
            if(j-i+1<k)
            j++;
            else if(j-i+1==k){
                // jaise hi window size hit hoga toh apan ko queue ke front meh pehla negative number mileag given ki uss window meh -ve number present ho toh hi dikhega
                
                if(q.size()==0)    // edge case jab list empty hogi means koi negative number nhi hai window meh toh apna 0 denge according to question

                ans.push_back(0);
                else{
                ans.push_back(q.front());
                
                if(arr[i]==q.front())
                    q.pop();
                    
                }
                
                i++;
                j++;
                
            }
            
        }
        
        return ans;
    }
};


// link to question https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1