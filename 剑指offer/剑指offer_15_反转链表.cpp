//
// Created by 李青坪 on 2019/2/26.
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
};

int n;

int main() {
    Solution s;
    ListNode *r = new ListNode(1);
    int a[] = {0, 2, 0, 1, 3, 4, 7, 6, 0, 5, 8, 9, 0, 3, 1, 2, 4};
//    int a[] = {};
    ListNode *value = r;
    for (int i : a) {
        ListNode *temp = new ListNode(i);
        value->next = temp;
        value = temp;
    }
    ListNode *result = s.ReverseList(r);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
}