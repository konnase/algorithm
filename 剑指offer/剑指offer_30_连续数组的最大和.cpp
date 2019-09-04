//
//  剑指offer_30_连续数组的最大和.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/20.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

int MINN = -(1 << 30);
#define NIL -1
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }
        int len = array.size();
        int a[len];
        memset(a, 0, len);
        a[0] = array[0];
        for (int i = 1; i < len; ++i) {
            a[i] =  a[i-1] + array[i] > array[i] ? a[i-1] + array[i] : array[i];
        }
        int maxSum = MINN;
        for (int i = 1; i < len; ++i) {
            maxSum = max(maxSum, a[i]);
        }
        return maxSum;
    }
};

int main(){
    Solution s;
    vector<int> pushV{6,-3,-2,7,-15,1,2,2};
    
    cout << s.FindGreatestSumOfSubArray(pushV);
}
