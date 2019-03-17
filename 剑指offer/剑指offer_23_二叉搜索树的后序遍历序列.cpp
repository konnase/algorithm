//
//  剑指offer_23_二叉搜索树的后序遍历序列.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/12.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Solution {
private:
    vector<int> a;
public:
    bool isBinaryTree(int l, int r){
        if (l >= r) {
            return true;
        }
        int root = a[r];
        int gap = -1;
        for (int i = l; i < r; ++i) {
            if (a[i] >= root) {
                gap = i;
            }
            if (gap != -1 && a[i] < root){
                return false;
            }
        }
        return isBinaryTree(l, gap-1) && isBinaryTree(gap, r-1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) {
            return true;
        }
        a = sequence;
        return isBinaryTree(0, a.size()-1);
    }
};

int main() {
    Solution s;
    vector<int> pushV;
    int a[9] = {3,2,4,5,11,10,15,13,7};
    for (int i = 0; i < 9; ++i) {
        pushV.push_back(a[i]);
    }
    cout << s.VerifySquenceOfBST(pushV) << endl;
}
