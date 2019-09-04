//
//  剑指offer_29_最小的k个数.cpp
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

class Solution {
private:
    vector<int> a;
public:
    void swap(int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    int partition(int l, int h) {
        int x = a[h];
        int i = l - 1;
        for (int j = l; j < h; ++j) {
            if (a[j] <= x) {
                swap(++i, j);
            }
        }
        swap(++i, h);
        return i;
    }
    
    pair<int, int> top_k(int l, int h, int k){
        pair<int, int> result;
        int i = partition(l, h);
        if (i + 1 == k) {
            result = make_pair(0, i);
            return result;
        }
        else if (i+1 > k){
            return top_k(l, i-1, k);
        }
        else {
            return top_k(i+1, h, k);
        }
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (input.empty() || k <= 0) { // 这里k <= 0 很关键。。
            return vector<int>();
        }
        if (input.size() < k){
            return vector<int>();
        }
        if (input.size() == k) {
            return input;
        }
        a = input;
        pair<int, int> i = top_k(0, input.size()-1, k);
        
        vector<int> result = vector<int>(a.begin(), a.begin()+i.second+1);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> pushV{4,8,7,6,10,2,9,5,3,2,6};
    
    vector<int> result = s.GetLeastNumbers_Solution(pushV, 13);
    for (auto i : result){
        cout<< i << " ";
    }
    cout << "end" << endl;
}
