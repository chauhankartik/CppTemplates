#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int countSubstrings(string s) {
                int res = 0;
                bool dp[s.length()][s.length()];
                memset(dp, false, sizeof dp);
                for(int gap = 0; gap < s.length(); gap++) {
                        for(int i = 0, j = gap; j < s.length(); i++, j++) {
                                if(gap == 0) { // gap 0 diagonal
                                        dp[i][j] = true;
                                        res += 1;
                                }
                                else if(gap == 1) {
                                        dp[i][j] = s[i] == s[j];
                                        if(dp[i][j]) res += 1;
                                }
                                else {
                                        if(s[i] == s[j] && dp[i+1][j-1]) {
                                                dp[i][j] = true;
                                                res += 1;
                                        } else dp[i][j] = false;
                                }
                        }       
                }
                return res;
        }
};
