//
//  160IntersectionofTwoLinkedLists.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
    map<ListNode*, int> degree;
public:
    // Too naive solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        if (headA == headB) {
            return headA;
        }
        ListNode *hA = headA, *hB = headB;
        while (headA->next || headB->next) {
            if (headA->next) {
                headA = headA->next;
            }
            if (headB->next) {
                headB = headB->next;
            }
        }
        if (headA != headB) {
            return NULL;
        }
        headA = hA; headB = hB;
        while (headA != headB) {
            if (headA) {
                headA = headA->next;
            } else {
                headA = hB;
            }
            if (headB) {
                headB = headB->next;
            } else {
                headB = hA;
            }
        }
        return headA;
    }
    
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        if (pHead->next == NULL) return pHead;
        ListNode* pre = pHead;
        ListNode* index;
        ListNode* next = pHead->next;
        pHead->next = NULL;
        while (next != NULL){
            index = next;
            next = next->next;
            index->next = pre;
            pre = index;
        }
        return pre;
    }
    
    /*
     首先遍历两个链表，得到长度；再将链表A翻转
     */
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        int len_a = 0, len_b = 0;
        ListNode *hA = headA, *hB = headB;
        while (headA || headB) {
            if (headA == headB) {
                return headA;
            }
            if (headA) {
                len_a++;
                headA = headA->next;
            }
            if (headB) {
                len_b++;
                headB = headB->next;
            }
        }
        headA = hA;
        headB = hB;
        int len_ab = 0;
        ReverseList(headA);
        while (headB) {
            len_ab++;
            headB = headB->next;
        }
        // No intersection
        if (len_ab == len_b) {
            return NULL;
        }
        int b = (len_ab + len_b - len_a)/2;
        headB = hB;
        while (headB) {
            if (!b) {
                return headB;
            }
            headB = headB->next;
            --b;
        }
        return NULL;
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
    cout << s.getIntersectionNode(a, b)->val << endl;
}
