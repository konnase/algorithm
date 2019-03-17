//
//  剑指offer_16_合并两个排序的链表.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/8.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL){
            return pHead2;
        }
        if(pHead2 == NULL){
            return pHead1;
        }
        ListNode* mergeHead = NULL;
        ListNode* current = NULL;
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val <= pHead2->val){
                if(mergeHead == NULL){
                    mergeHead = current = pHead1;
                }else{
                    current->next = pHead1;
                    current = current->next;
                }
                pHead1 = pHead1->next;
            }else{
                if(mergeHead == NULL){
                    mergeHead = current = pHead2;
                }else{
                    current->next = pHead2;
                    current = current->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 == NULL){
            current->next = pHead2;
        }else{
            current->next = pHead1;
        }
        return mergeHead;
    }
};

int main() {
    Solution s;
    ListNode *r = new ListNode(1);
    ListNode *r2 = new ListNode(2);
    int a[] = {3, 4, 5, 6, 12, 14};
    int b[] = {7, 9, 10, 15, 18, 19, 20, 23, 31, 32, 34};
    //    int a[] = {};
    ListNode *value = r;
    for (int i : a) {
        ListNode *temp = new ListNode(i);
        value->next = temp;
        value = temp;
    }
    value = r2;
    for (int i:b) {
        ListNode * temp = new ListNode(i);
        value->next = temp;
        value = temp;
    }
    ListNode *result = s.Merge(r, r2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
}
