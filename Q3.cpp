#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(string &pat, string &txt) {
        int k = pat.length();
        int ans = 0;
        map<char, int> mp;
        
        for (char ch : pat) {
            mp[ch]++;
        }
        
        int count = mp.size();  // number of distinct characters
        int i = 0, j = 0;
        
        while (j < txt.length()) {
            // Decrease freq of current character from txt
            if (mp.find(txt[j]) != mp.end()) {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    count--;  // one unique char completely matched
            }
            
            // Window size less than k, just move j
            if (j - i + 1 < k)
                j++;
            
            // Window of size k
            else if (j - i + 1 == k) {
                if (count == 0)
                    ans++;  // anagram found
                
                // Now slide the window: remove i-th character
                if (mp.find(txt[i]) != mp.end()) {
                    if (mp[txt[i]] == 0)
                        count++;  // unmatched character is coming back
                    mp[txt[i]]++;
                }
                
                i++;
                j++;
            }
        }
        return ans;
    }
};

// link to question https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1