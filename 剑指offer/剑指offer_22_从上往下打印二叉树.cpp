//
//  剑指offer_22_从上往下打印二叉树.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/11.
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
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> tree;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* head = q.front();
            q.pop();
            tree.push_back(head->val);
            TreeNode* l = head->left;
            TreeNode* r = head->right;
            if (l) {
                q.push(l);
            }
            if (r) {
                q.push(r);
            }
        }
        return tree;
    }
};

int main() {
    Solution s;
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(8);
    r->left->right->left = new TreeNode(7);
    r->right->left = new TreeNode(4);
    
    vector<int> result = s.PrintFromTopToBottom(r);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
}
