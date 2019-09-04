//
//  5最长回文子串.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/22.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define MAXN 10000
#define NIL -10000000
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int len = s.length();
        int t[len][len];
        for (int i = 0; i < len; ++i) {
            memset(t[i], 0, len * 4);
        }
        for (int i = 0; i < len; ++i) {
            t[i][i] = 1;
        }
        
        int l=0, r=0, maxLen = 0;
        for (int j = 1; j < len; ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j]) {
                    t[i][j] = t[i+1][j-1] + 2 > 0 ? t[i+1][j-1] + 2 : NIL;
                    if (maxLen < t[i][j]) {
                        maxLen = t[i][j];
                        l = i;
                        r = j;
                    }
                } else {
                    t[i][j] = NIL;
                }
            }
        }
        return s.substr(l, r-l+1);
    }
};

int main(){
    Solution s;
    string str = "abcdadc";
    
    cout << s.longestPalindrome(str);
}
