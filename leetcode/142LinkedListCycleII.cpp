//
//  142LinkedListCycleII.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include <map>
class Solution {
private:
    map<ListNode*, int> degree;
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        while (head != NULL) {
            if (degree.find(head) != degree.end()) {
                degree[head]++;
            } else {
                degree[head] = 1;
            }
            if (degree[head] == 2) {
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
    ListNode *detectCycle2(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *low = head, *fast = head;
        while (fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
            if (low == fast) {
                ListNode *low2 = head;
                while (low != low2) {
                    low = low->next;
                    low2 = low2->next;
                }
                return low;
            }
        }
        return NULL;
    }
};
