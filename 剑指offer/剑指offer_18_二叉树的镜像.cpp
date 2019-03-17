//
//  剑指offer_18_二叉树的镜像.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/8.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL) {
            return;
        }
        TreeNode* head = pRoot, *temp;
        temp = head->left;
        head->left = head->right;
        head->right = temp;
        Mirror(head->left);
        Mirror(head->right);
    }
};

void printTree(TreeNode *pRoot) {
    if (pRoot == NULL) {
        return;
    }
    TreeNode* head = pRoot;
    cout << head->val << endl;
    printTree(head->left);
    printTree(head->right);
}

int main() {
    Solution s;
    TreeNode *r = new TreeNode(1);

    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(8);
    r->right->left = new TreeNode(4);
    
    s.Mirror(r);
    printTree(r);
}

