//
// Created by 李青坪 on 2019/2/25.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * 可以new一个vector temp，遍历array，如果是奇数就往下一个奇数位置放；如果是偶数就往temp push，最后把temp里面的数据push到array里面去
     */
    void reOrderArray(vector<int> &array) {
        if (array.empty()) return;
        int len = array.size();
        vector<int> temp;
        int l = 0;
        for (int i = 0; i < len; ++i) {
            if (array[i] % 2 != 0) {
                array[l++] = array[i];
            } else {
                temp.push_back(array[i]);
            }
        }
        for (int i = 0; i < len - l; ++i) {
            array.pop_back();
        }
        for (int i = 0; i < temp.size(); ++i) {
            array.push_back(temp[i]);
        }
    }
};

int n;

int main() {
    Solution s;
    vector<int> r;
    int a[] = {0, 2, 0, 1, 3, 4, 7, 6, 0, 5, 8, 9, 0, 3, 1, 2, 4, 7};
//    int a[] = {};
    int value;
    for (int i : a) {
        value = i;
        r.push_back(value);
    }
    s.reOrderArray(r);
    for (int i:r) {
        cout << i << " ";
    }
}