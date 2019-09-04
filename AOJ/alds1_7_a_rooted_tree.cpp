//
// Created by 李青坪 on 2018/10/16.
//

/*
 * 坑
 * 1. tree需要初始化，使所有node的属性都赋值为NIL
 * 2. 根结点不一定是结点0，所以再递归求深度的时候要先找出根结点
 */
#include "cstdio"
using namespace std;
#define MAXN 100000
#define NIL -1


struct Node{
    int parent;
    int left;
    int right;
};
Node tree[MAXN];
int depth[MAXN];


void getDepth(int node, int dep){
    depth[node] = dep;
    if (tree[node].right != NIL) getDepth(tree[node].right, dep);
    if (tree[node].left != NIL) getDepth(tree[node].left, dep+1);
}

void printTree(int n, int root){
    getDepth(root, 0);
    for (int i = 0; i < n; ++i) {
        printf("node %d: parent = %d, depth = %d, ", i, tree[i].parent, depth[i]);
        if (depth[i] == 0){
            int iter = tree[i].left;
            if (iter == NIL) {
                printf("root, []\n");
                continue;
            }
            printf("root, [%d", iter);
            while(tree[iter].right != NIL){
                iter = tree[iter].right;
                printf(", %d", iter);
            }
            printf("]");
        }else if(tree[i].left != NIL){
            int iter = tree[i].left;
            printf("internal node, [%d", iter);
            while(tree[iter].right != NIL){
                iter = tree[iter].right;
                printf(", %d", iter);
            }
            printf("]");
        }
        else {
            printf("leaf, []");
        }
        printf("\n");
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for (int l = 0; l < n; ++l) {
        tree[l].parent = NIL;
        tree[l].left = NIL;
        tree[l].right = NIL;
    }
    for (int i = 0; i < n; ++i) {
        int node_id, degree;
        scanf("%d %d", &node_id, &degree);
        if (degree == 0){
            tree[node_id].left = NIL;
            continue;
        }
        int children[degree+1];
        for (int k = 0; k < degree+1; ++k) {
            children[k] = NIL;
        }
        for (int j = 0; j < degree; ++j) {
            scanf("%d", &children[j]);
            tree[children[j]].parent = node_id;
        }
        tree[node_id].left = children[0];
        for (int j = 0; j < degree; ++j) {
            tree[children[j]].right = children[j+1];
        }
    }
    int root;
    for (int l = 0; l < n; ++l) {
        if (tree[l].parent == NIL) {
            root = l;
            break;
        }
    }
    printTree(n, root);
}
/*
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0
 */