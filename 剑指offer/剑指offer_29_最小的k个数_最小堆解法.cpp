//
//  剑指offer_29_最小的k个数_最小堆解法.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/19.
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
    return a > b;
}

class Solution {
private:
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty()) {
            return vector<int>();
        }
        if (input.size() < k){
            return vector<int>();
        }
        if (input.size() == k) {
            return input;
        }
        make_heap(input.begin(), input.begin()+k);
        for (int i = k; i < input.size(); ++i) {
            if (input[i] < input[0]) {
                
                input[0] = input[i];
                make_heap(input.begin(), input.begin()+k);
            }
        }
        sort_heap(input.begin(), input.begin()+k);
        return vector<int>(input.begin(), input.begin()+k);
    }
};

int main(){
    Solution s;
    vector<int> pushV{4,8,7,6,10,2,9,5,6,2,6};
    
    vector<int> result = s.GetLeastNumbers_Solution(pushV, 4);
    for (auto i : result){
        cout<< i << " ";
    }
}
