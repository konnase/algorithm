//
//  剑指offer_27_字符串的排列.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/16.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

typedef long long ll;

struct Cmp {
    bool operator() (char a, char b) {
        return a < b;
    }
}mycmp;  //等价于：Cmp mycmp;

class Solution {
private:
    set<string> list;
public:
    void mySwap(string &s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    
    void recursive(string s, int i){
        if (i == s.length()-1) {
            list.insert(s);
        }else {
            for (int j = i; j < s.length(); ++j) {
                mySwap(s, i, j);
                recursive(s, i+1);
                mySwap(s, i, j);
            }
        }
    }
    
    vector<string> Permutation(string str) {
        if (str.length() == 0) {
            return vector<string>();
        }
        recursive(str, 0);
        vector<string> result;
        set<string>::iterator it;
        for (it = list.begin(); it != list.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};

int main() {
    Solution s;
    string str= "abcb";
    vector<string> result = s.Permutation(str);
    vector<string>::iterator it;
    for (it = result.begin(); it != result.end(); ++it) {
        cout << *it <<endl;
    }
}
