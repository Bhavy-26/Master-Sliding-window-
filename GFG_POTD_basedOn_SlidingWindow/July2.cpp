#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    return 0;
}

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int i = 0, j = 0;
        int n = s.length();
        map<char, int> mp;
        int ans = -1;

        while (j < n) {
            mp[s[j]]++;

            // Shrink the window if there are more than k distinct chars
            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            // If exactly k distinct characters, update the max length
            if (mp.size() == k) {
                ans = max(ans, j - i + 1);
            }

            j++;
        }

        return ans;
    }
};
