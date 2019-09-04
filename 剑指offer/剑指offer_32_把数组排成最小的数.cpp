//
//  剑指offer_32_把数组排成最小的数.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/21.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define MAXN 10000
#define NIL -1
using namespace std;

bool cmp(const int &a, const int &b){
    string a1 = to_string(a);
    string b1 = to_string(b);
    string c1 = a1 + b1;
    string c2 = b1 + a1;
    return stoi(c1) < stoi(c2);
}

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string r;
        for (auto i : numbers) {
            string a = to_string(i);
            r += a;
        }
        return r;
    }
};

int main(){
    Solution s;
    vector<int> pushV{3, 32, 321};
    
    cout << s.PrintMinNumber(pushV);
}
