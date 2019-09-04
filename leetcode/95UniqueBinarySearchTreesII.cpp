//
//  95UniqueBinarySearchTreesII.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/22.
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> dfs(int l, int r) {
        vector<TreeNode*> result;
        if (l > r) {
            result.push_back(NULL);
            return result;
        }
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> left = dfs(l, i-1);
            vector<TreeNode*> right = dfs(i+1, r);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        if (n == 1) {
            vector<TreeNode*> r;
            r.push_back(new TreeNode(1));
            return r;
        }
        return dfs(1, n);
    }
};

int main(){
    Solution s;
    vector<int> pushV{4,8,7,6,10,9,5,3,2,1};
    
    vector<TreeNode*> result = s.generateTrees(3);
    cout << result.size() << endl;
}
