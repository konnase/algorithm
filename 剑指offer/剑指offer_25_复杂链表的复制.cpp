//
//  剑指offer_25_复杂链表的复制.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/13.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
    label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) {
            return NULL;
        }
        RandomListNode* head = pHead;
        while (head) {
            RandomListNode* cp = new RandomListNode(head->label);
            cp->next = head->next;
            head->next = cp;
            head = cp->next;
        }
        head = pHead;
        while (head) {
            RandomListNode* cp = head->next;
            if (head->random) {
                cp->random = head->random->next;
            }
            head = cp->next;
        }
        head = pHead->next;
        while (head->next) {
            RandomListNode* org = head->next;
            head->next = org->next;
            head = org->next;
        }
        return pHead->next;
    }
};

int main() {
    Solution s;
//    RandomListNode *head = new RandomListNode(5);
//    RandomListNode *temp = new RandomListNode(3);
//    head->next = temp;
//    temp->next = new RandomListNode(6);
//    temp->next->next = new RandomListNode(8);
//    temp->next->next->next = new RandomListNode(12);
//    head->random = temp->next->next;
//    temp->random = temp->next->next->next;
//    temp->next->next->random = head;
    RandomListNode *temp = new RandomListNode(1);
    temp->next = new RandomListNode(2);
    temp->next->next = new RandomListNode(3);
    temp->next->next->next = new RandomListNode(4);
    temp->next->next->next->next = new RandomListNode(5);
    temp->random = temp->next->next;
    temp->next->random = temp->next->next->next->next;
    temp->next->next->next->random = temp->next;
    RandomListNode* result = s.Clone(temp);
//    RandomListNode* result = s.Clone(head);
    while (result) {
        cout << result->label << " ";
        if (result->random) cout << result->random->label;
        cout << endl;
        result = result->next;
    }
}
