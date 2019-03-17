//
//  剑指offer_21_栈的压入弹出序列.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/11.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int j = 0;
        for (int i = 0; i < pushV.size(); ++i){
            s.push(pushV[i]);
            while (j < popV.size() && s.top() == popV[j]) {
                cout << s.top() << " " << popV[j] << endl;
                s.pop();
                ++j;
            }
        }
        return s.empty();
    }
};

int main() {
    Solution s;
    vector<int> pushV, popV;
    int a[10] = {4,8,7,6,10,9,5,3,2,1};
    for (int i = 0; i < 10; ++i) {
        pushV.push_back(i+1);
        popV.push_back(a[i]);
    }
    cout << s.IsPopOrder(pushV, popV) << endl;
}
