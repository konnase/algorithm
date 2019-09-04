//
//  剑指offer_36_两个链表的第一个公共结点.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/31.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        if (pHead1 == pHead2) {
            return pHead1;
        }
        ListNode* a = pHead1;
        ListNode* b = pHead2;
        ListNode* a_last = NULL, *b_last = NULL;
        while (a != b) {
            if (a->next == NULL) {
                a_last = a;
                a = pHead2;
            } else {
                a = a->next;
            }
            if (b->next == NULL) {
                b_last = b;
                b = pHead1;
            } else {
                b = b->next;
            }
            if ((a_last && b_last) && (a_last != b_last)){
                return NULL;
            }
        }
        return a;
    }
};

int main(){
    Solution s;
    ListNode *a, *b;
    a = new ListNode(4);
    a->next = new ListNode(1);
    a->next->next = new ListNode(8);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    b = new ListNode(5);
    b->next = new ListNode(0);
    b->next->next = new ListNode(1);
    b->next->next->next = a->next->next;
    cout << s.FindFirstCommonNode(a, b)->val << endl;
}
