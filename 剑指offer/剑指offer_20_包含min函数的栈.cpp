//
//  剑指offer_20_包含min函数的栈.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#define MAXN 10000
#define NIL -1
using namespace std;

class Solution {
private:
    stack<int> s1, s2;
public:
    void push(int value) {
        if (s1.empty()) {
            s2.push(value);
        } else {
            if (value <= s2.top()) {
                s2.push(value);
            }
        }
        s1.push(value);
    }
    void pop() {
        if (s1.empty()) {
            return;
        } else {
            if (s1.top() == s2.top()) {
                s2.pop();
            }
            s1.pop();
        }
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
};

int n;

int main(){
    Solution s;
    
}
