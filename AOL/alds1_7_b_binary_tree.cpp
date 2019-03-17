//
// Created by 李青坪 on 2018/10/17.
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

void getDepth(int start, int dep){
    depth[start] = dep;
    if (tree[start].left != NIL) getDepth(tree[start].left, dep+1);
    if (tree[start].right != NIL) getDepth(tree[start].right, dep+1);
}

int getHeight(int start){
    if (start == NIL) return -1;
    if (tree[start].left == NIL && tree[start].right == NIL){
        height[start] = 0;
        return 0;
    }
    height[start] = max(1+getHeight(tree[start].left), 1+getHeight(tree[start].right));
    return height[start];
}

void printTree(int n){
    for (int i = 0; i < n; ++i) {
        printf("node %d: parent = %d, ", i, tree[i].parent);
        int parent = tree[i].parent;
        if (parent != NIL){
            if (tree[parent].left != i) printf("sibling = %d, ", tree[parent].left);
            else printf("sibling = %d, ", tree[parent].right);

        } else{
            printf("sibling = -1, ");
        }
        bool isLeaf = false;
        if (tree[i].left == NIL && tree[i].right == NIL) {
            isLeaf = true;
            printf("degree = %d, ", 0);
        }
        else{
            int degree = (tree[i].left != NIL && tree[i].right != NIL) ? 2 : 1;
            printf("degree = %d, ", degree);
        }
        printf("depth = %d, height = %d, ", depth[i], height[i]);
        if (depth[i] == 0){
            printf("root");
        } else if (isLeaf){
            printf("leaf");
        }else printf("internal node");
        printf("\n");
    }
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
    int root = getRoot(n);
//    printf("%d", root);
    getDepth(root, 0);
    getHeight(root);
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