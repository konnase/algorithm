//
//  剑指offer_47_圈中剩下最小的数.cpp
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
    int next(int i, int n, bool visit[]) {
        while (visit[i]) {
            i = (i+1)%n;
        }
        return i;
    }
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return 0;
        }
        if (m == 1) {
            return n-1;
        }
        int remain = n, count = 0, i = 0;
        bool visit[n];
        memset(visit, false, sizeof(visit));
        while (remain > 1) {
            if (count == m-1) {
                visit[i] = 1;
                count = 0;
                i = next((i+1)%n, n, visit);
                remain--;
                continue;
            }
            count++;
            i = next((i+1)%n, n, visit);
        }
//        for (auto j : visit) cout << j << " ";
        return next((i+1)%n, n, visit);
    }
};

int main(){
    Solution s;
    vector<int> pushV{4,8,7,6,10,9,5,3,2,1};
    
    cout << s.LastRemaining_Solution(6, 4);
}
