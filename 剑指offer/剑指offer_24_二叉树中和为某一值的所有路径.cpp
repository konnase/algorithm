//
//  剑指offer_24_二叉树中和为某一值的所有路径.cpp
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

struct Cmp {
    bool operator () (vector<int> a, vector<int> b){
        return a.size() > b.size();
    }
}mycmp;

class Solution {
private:
    vector<vector<int>> result;
    int expNumber;
public:
    bool cmp(vector<int> a, vector<int> b) {
        return a.size() > b.size();
    }
    // 这里不应该把a压栈。用一个独立的vector，每次递归就把当前元素压栈，如果
    // 有满足的路径就把新建一个vector加入result，找左子树和右子树后，把当前元素又删除。
    void FindSubPath(TreeNode* root,vector<int> a, int sum){
        if (root == NULL) {
            return;
        }
        if (root->val + sum > expNumber) {
            return;
        }
        vector<int> temp;
        for (int i= 0; i < a.size(); ++i) {
            temp.push_back(a[i]);
        }
        temp.push_back(root->val);
        
        if (root->val + sum == expNumber) {
            if (!root->left && !root->right) {
                result.push_back(temp);
            }
            return;
        }
        if (root->val + sum < expNumber) {
            FindSubPath(root->left, temp, sum + root->val);
            FindSubPath(root->right, temp, sum + root->val);
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        expNumber = expectNumber;
        FindSubPath(root, vector<int>(), 0);
        sort(result.begin(), result.end(), mycmp);
        return result;
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
    r->right->left->right = new TreeNode(1);
    vector<vector<int>> result = s.FindPath(r, 9);
    for (auto i: result){
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
