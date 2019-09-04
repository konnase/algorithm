//
// Created by 李青坪 on 2018/10/20.
//

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};

int pos;
vector<int > pre, in, back;
Node tree[MAXN];

void initTree(int n){
    for (int i = 0; i < n; ++i) {
        tree[i].parent = tree[i].left = tree[i].right = NIL;
    }
}

void postorder(int node){
    if (tree[node].left != NIL) postorder(tree[node].left);
    if (tree[node].right != NIL) postorder(tree[node].right);
    printf("%d", node);
    if (node != pre[0]) printf(" ");
}

int reconstruction(int left, int right, int parent){
    if (left >= right) return NIL;
    int root = pre[pos++];
    int index = find(in.begin(), in.end(), root) - in.begin();
    tree[root].parent = parent;
    int leftRoot = reconstruction(left, index, root);
    int rightRoot = reconstruction(index+1, right, root);
    tree[root].left = leftRoot;
    tree[root].right = rightRoot;
    back.push_back(root);
    return root;
}

int main(){
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        pre.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        in.push_back(num);
    }
    initTree(n);

    pos = 0;
    reconstruction(0, in.size(), NIL);
//    for (int j = 0; j < back.size(); ++j) {
//        if (j) printf(" ");
//        printf("%d", back[j]);
//    }
//    printf("\n");
    postorder(pre[0]);
    printf("\n");
}

/*
5
1 2 3 4 5
3 2 4 1 5
 */