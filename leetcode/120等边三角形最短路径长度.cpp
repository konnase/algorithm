//
//  120等边三角形最短路径长度.cpp
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
#define NIL -1
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return triangle[0][0];
        }
        vector<int> re = vector<int>(triangle[len-1]);
        for (int i = len - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                re[j] = min(re[j], re[j+1]) + triangle[i][j];
            }
        }
        return re[0];
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle;
    triangle.push_back(vector<int>({2}));
    triangle.push_back(vector<int>({3,4}));
    triangle.push_back(vector<int>({6,5,7}));
    triangle.push_back(vector<int>({4,1,8,3}));
    cout << s.minimumTotal(triangle);
}
