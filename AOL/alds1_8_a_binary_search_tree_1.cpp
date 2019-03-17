//
// Created by 李青坪 on 2018/10/23.
//
/*
 * deleteNode()方法中，找待删除的node y的操作是关键
 * 如果root有两个子结点，那么要找从中序遍历中找root的后继
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
    int value;
    Node *parent, *left, *right;
};
Node *head, *NIL;

void insertNode(int value){
    Node *x = head;
    Node *y = NIL;  //表示父节点
    while (x != NIL){
        y = x;
        if (value < x->value){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    Node *z = new(Node);
    z->value = value;
    z->left = NIL;
    z->right = NIL;
    if (y != NIL){
        if (z->value < y->value){
            y->left = z;
        }
        else{
            y->right = z;
        }
        z->parent = y;
    } else{
        head = z;
    }
}

bool findNode(Node *root, int value ){
    if (root == NIL) return false;
    if (root->value == value) return true;
    bool left= false, right= false;
    if (root->value < value)
        right = findNode(root->right, value);
    if (root->value > value)
        left = findNode(root->left, value);
    return left || right;
}

Node *getSuccessor(Node *root){
    if (root->right !=NIL){
        Node *min = root->right;
        while (min->left != NIL){
            min = min->left;
        }
        return min;
    } else{
        Node *min = root->parent;
        while (min != NIL && root == min->right){
            root = min;
            min = root->parent;
        }
        return min;
    }
}

void deleteNode(int value){
    Node *root = head;
    while (root->value != value){
        if (root->value < value) {
            root = root->right;
        }
        else if (root->value > value) {
            root = root->left;
        }
    }
    Node *y;  //待删除的点
    if (root->left == NIL || root->right == NIL){
        y = root;
    } else{
        y = getSuccessor(root);
    }
    if (y->left == NIL && y->right == NIL){
        if (y->parent != NIL){
            if (y->parent->right == y){
                y->parent->right = NIL;
            } else {
                y->parent->left = NIL;
            }
        } else{
           head = NIL;
        }
    }
    else if (y->left == NIL && y->right != NIL){
        if (y->parent != NIL){
            if (y->parent->right == root){
                y->parent->right = y->right;
                y->right->parent = y->parent;
            } else {
                y->parent->left = y->right;
            }
        } else {
            head = y->right;
        }
    }
    else if (y->left != NIL && y->right == NIL){
        if (y->parent != NIL){
            if (y->parent->right == root){
                y->parent->right = y->left;
                y->left->parent = y->parent;
            } else {
                y->parent->left = y->left;
            }
        } else{
            head = y->left;
        }
    }
    if (y != root){
        root->value = y->value;
    }
    free(y);
}

void inOrder(Node *x){
    if (x != NIL){
        inOrder(x->left);
        printf(" %d", x->value);
        inOrder(x->right);
    }
}

void preOrder(Node *x){
    if (x != NIL){
        printf(" %d", x->value);
        preOrder(x->left);
        preOrder(x->right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    head = NIL;
    char command[10];
    int value;
    for (int i = 0; i < n; ++i) {
        scanf("%s", command);
        if (command[0] == 'i'){
            scanf("%d", &value);
            insertNode(value);
        } else if (command[0] == 'f'){
            scanf("%d", &value);
            if (findNode(head, value)) printf("yes\n");
            else printf("no\n");
        } else if (command[0]== 'd'){
            scanf("%d", &value);
            deleteNode(value);
        }
        else{
            inOrder(head);
            printf("\n");
            preOrder(head);
            printf("\n");
        }
    }
    return 0;
}
/*
5
insert 9
insert 4
insert 15
delete 9
print

18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
print

 */