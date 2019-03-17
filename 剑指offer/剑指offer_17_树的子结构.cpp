//
//  剑指offer_17_树的子结构.cpp
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
private:
    bool isSubtree(TreeNode* p1, TreeNode* p2) {
        if (p2 == NULL) {
            return true;
        }
        if (p1 == NULL) {
            return false;
        }
        if (p1->val == p2->val) {
            return isSubtree(p1->left, p2->left) && isSubtree(p1->right, p2->right);
        }
        return false;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1 == NULL || pRoot2 == NULL) {
            return false;
        }
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};

int main() {
    Solution s;
    TreeNode *r = new TreeNode(1);
    TreeNode *r2 = new TreeNode(2);
    //    int a[] = {};
    TreeNode *value = r;
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(8);
    r->right->left = new TreeNode(4);
    
    r2->left = new TreeNode(6);
    r2->right = new TreeNode(8);
    cout << s.HasSubtree(r, r2) << endl;
}
