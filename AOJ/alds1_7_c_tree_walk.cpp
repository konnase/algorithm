//
// Created by 李青坪 on 2018/10/1.
//

#include <cstdio>
#include <algorithm>

using namespace std;
#define MAXN 25
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};

Node tree[MAXN];
int depth[MAXN];
int height[MAXN];

int getRoot(int n){
    for (int i = 0; i < n; ++i) {
        if (tree[i].parent == NIL) return i;
    }
}

void initTree(int n){
    for (int i = 0; i < n; ++i) {
        tree[i].parent = tree[i].left = tree[i].right = NIL;
    }
}

void preorder(int node){
    printf(" %d", node);
    if (tree[node].left != NIL) preorder(tree[node].left);
    if (tree[node].right != NIL) preorder(tree[node].right);
}

void inorder(int node){
    if (tree[node].left != NIL) inorder(tree[node].left);
    printf(" %d", node);
    if (tree[node].right != NIL) inorder(tree[node].right);
}

void postorder(int node){
    if (tree[node].left != NIL) postorder(tree[node].left);
    if (tree[node].right != NIL) postorder(tree[node].right);
    printf(" %d", node);
}

void printTree(int n){
    printf("Preorder\n");
    preorder(getRoot(n));
    printf("\nInorder\n");
    inorder(getRoot(n));
    printf("\nPostorder\n");
    postorder(getRoot(n));
    printf("\n");
}


int main(){
    int n;
    scanf("%d", &n);
    initTree(n);
    int node_id, left, right;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &node_id, &left, &right);
        tree[node_id].left = left;
        tree[node_id].right = right;
        if (left != NIL) tree[left].parent = node_id;
        if (right != NIL) tree[right].parent = node_id;
    }
    printTree(n);
}
/*
9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
 */