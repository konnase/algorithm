//
//  剑指offer_39_二叉平衡树判断.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/4/2.
//  Copyright © 2019 李青坪. All rights reserved.
//
#include <iostream>

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
public:
    pair<int, bool> TreeDepth(TreeNode* pRoot) {
        if (!pRoot)
            return make_pair(0, true);
        pair<int, bool> l_d = TreeDepth(pRoot->left);
        pair<int, bool> r_d = TreeDepth(pRoot->right);
        if (!l_d.second || !r_d.second) {
            return make_pair(max(l_d.first+1, r_d.first+1), false);
        }
        int d = l_d.first - r_d.first;
        if (d > 1 || d < -1) {
            return make_pair(max(l_d.first+1, r_d.first+1), false);
        }
        return make_pair(max(l_d.first+1, r_d.first+1), true);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return TreeDepth(pRoot).second;
    }
};
