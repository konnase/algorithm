//
//  剑指offer_26_二叉搜索树与双向链表.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/15.
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
    TreeNode* pre, *head;
public:
    void dfs(TreeNode* pRootOfTree) {
        if (pRootOfTree == NULL) {
            return;
        }
        if (pRootOfTree->left == NULL) {
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
        else Convert(pRootOfTree->left);
        if (pRootOfTree->right != NULL) {
            Convert(pRootOfTree->right);
        }
        else if (pRootOfTree->left != NULL){
            pre->right = pRootOfTree;
            pRootOfTree->left = pre;
            pre = pRootOfTree;
        }
    }
    TreeNode* Convert2(TreeNode* pRootOfTree)
    {
        pre = new TreeNode(0);
        head = pre;
        dfs(pRootOfTree);
        return head->right;
    }
    
    // 不创建新的节点
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL) {
            return NULL;
        }
        if (pRootOfTree->left == NULL && pRootOfTree->right == NULL){
            return pRootOfTree;
        }
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* lLate = left;
        while (lLate != NULL && lLate->right != NULL) {
            lLate = lLate->right;
        }
        if (left != NULL) {
            lLate->right = pRootOfTree;
            pRootOfTree->left = lLate;
        }
        
        // 右子树
        TreeNode* right = Convert(pRootOfTree->right);
        if (right != NULL) {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left != NULL ? left:pRootOfTree;
    }
};

int main() {
    Solution s;
    TreeNode *r = new TreeNode(32);
    r->left = new TreeNode(20);
    r->right = new TreeNode(34);
    r->left->left = new TreeNode(18);
    r->left->right = new TreeNode(25);
    r->left->right->left = new TreeNode(21);
    r->right->left = new TreeNode(33);
    
    TreeNode* result = s.Convert(r);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->right;
    }
}
