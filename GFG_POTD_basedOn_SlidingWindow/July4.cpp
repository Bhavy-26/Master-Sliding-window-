#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    return 0;
}

class Solution {
  public:
    int substrCount(string &s, int k) {
        int i = 0, j = 0;
        int n = s.length();
        map<char, int> mp;
        int count = 0;

        while (j < n) {
            mp[s[j]]++;

            if (j - i + 1 < k) {
                j++;
            } 
            else if (j - i + 1 == k) {
                if (mp.size() == k - 1)  // Correct condition
                    count++;

                // Shrink the window
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
                j++;
            }
        }

        return count;
    }
};
