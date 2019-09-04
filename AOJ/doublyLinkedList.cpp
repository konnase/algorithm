//
// Created by 李青坪 on 2018/10/2.
//


#include <cstdlib>
#include <cstdio>

using namespace std;

struct Node{
    int key;
    Node *pre, *next;
};

class DLinkedList{
public:
    Node *head;
    DLinkedList(){
        head = new(Node);
        head->pre = head;
        head->next = head;
    }
    void addNode(int key){
        Node *node = new(Node);
        node->key = key;
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
    }
    Node* searchNode(int key){
        Node *cur = head->next;
        while (cur != head && cur->key != key){
            cur = cur->next;
        }
        return cur;
    }
    void deleteNode(Node *node){
        if (node == head) return;
        node->next->pre = node->pre;
        node->pre->next = node->next;
        free(node);
    }
};

int main(){
    int n;
    scanf("%d", &n);
    DLinkedList list = DLinkedList();
    for (int i = 0; i < n; ++i) {
        char command[20];
        scanf("%s", command);
        int key;
        if (command[0] == 'i'){
            scanf("%d", &key);
            list.addNode(key);
        }
        else if (command[0] == 'd'){
            if (command[6] == 'F'){
                list.deleteNode(list.head->next);
            } else if (command[6] == 'L'){
                list.deleteNode(list.head->pre);
            } else{
                scanf("%d", &key);
                list.deleteNode(list.searchNode(key));
            }
        }

    }
    printf("%d", list.head->next->key);
    Node *cur = list.head->next->next;
    while(cur != list.head){
        printf(" %d", cur->key);
        cur = cur->next;
    }
    printf("\n");
    return 0;
}

 /*
7
insert 5
insert 2
insert 3
insert 1
delete 3
insert 6
delete 5
 */