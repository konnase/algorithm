//
// Created by 李青坪 on 2019/2/3.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int n, m;


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        // 此方法相比于我的方法差异在：此方法是将pre和vin切分之后做递归，而我的方法是将整个pre和vin压入堆栈，导致栈溢出。
        // 我的方法如果将pre和vin作为全局变量的话不会导致栈溢出。
        if (pre.size() == NULL)
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        int i;
        for (i = 0; i < vin.size() && vin[i] != pre[0]; i++);
        vector<int> pre_left, in_left,pre_right,in_right;
        int pre_i = 1;
        for (int j = 0; j < vin.size(); j++)
        {
            if (j < i)
            {
                in_left.push_back(vin[j]);
                pre_left.push_back(pre[pre_i]);
                pre_i++;
            }
            else if (j>i)
            {
                in_right.push_back(vin[j]);
                pre_right.push_back(pre[pre_i]);
                pre_i++;
            }
        }
        root->left = reConstructBinaryTree(pre_left, in_left);
        root->right = reConstructBinaryTree(pre_right, in_right);
        return root;
//        TreeNode *tree = new TreeNode(pre[0]);
//        return dfs(0, 0, pre.size() - 1, pre, vin);  //注意是pre.size()-1
    }

    TreeNode *dfs(int index, int left, int right, vector<int> pre, vector<int> vin) {
        if (left > right) {
            return NULL;
        }
        vector<int>::iterator it = find(vin.begin(), vin.end(), pre[index]); //搜索范围是整个vin数组
        if (it == vin.end()) {

        }
        int mid_index = it - vin.begin();
        TreeNode *tree = new TreeNode(pre[index]);
        TreeNode *lchild, *rchild;
        //三种不同的情况
        if (mid_index - left > 1)
            lchild = dfs(index + 1, left, mid_index - 1, pre, vin);
        else if (mid_index - left == 1) {
            lchild = new TreeNode(vin[left]);
        } else {
            lchild = NULL;
        }
        if (right - mid_index > 1)
            rchild = dfs(mid_index + 1, mid_index + 1, right, pre, vin);
        else if (right - mid_index == 1) {
            rchild = new TreeNode(vin[right]);
        } else {
            rchild = NULL;
        }
        tree->left = lchild;
        tree->right = rchild;
        return tree;
    }
};

void printTree(TreeNode *treeNode) {
    cout << treeNode->val << " ";
    if (treeNode->left != NULL) {
        printTree(treeNode->left);
    }
    if (treeNode->right != NULL) {
        printTree(treeNode->right);
    }
}

void vinTree(TreeNode *treeNode) {
    if (treeNode->left != NULL) {
        vinTree(treeNode->left);
    }
    cout << treeNode->val << " ";
    if (treeNode->right != NULL) {
        vinTree(treeNode->right);
    }
}

int main() {
    vector<int> pre;
    vector<int> vin;
    int pres[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int vins[] = {4, 7, 2, 1, 5, 3, 8, 6};
    for (int i = 0; i < 8; ++i) {
        pre.push_back(pres[i]);
        vin.push_back(vins[i]);
    }
    Solution s;
    TreeNode *treeNode = s.reConstructBinaryTree(pre, vin);
    printTree(treeNode);
    cout << endl;
    vinTree(treeNode);
}

/*
3 4
1 4 7 8
2 6 8 9
6 10 12 20
 */