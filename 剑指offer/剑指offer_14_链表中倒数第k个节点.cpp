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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        if (k <= 0) return NULL;
        ListNode *head = pListHead;
        ListNode *result = pListHead;
        int l = 0;
        while (head != NULL) {
            ++l;
            if (l >= k + 1) {
                result = result->next;
            }
            head = head->next;
        }
        if (l < k) return NULL;
        return result;
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
    cout << s.FindKthToTail(r, 4)->val << endl;
}