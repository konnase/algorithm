//
// Created by 李青坪 on 2019/2/3.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n, m;


struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> result;
        stack<int> s;
        ListNode *p = head;
        while (p != NULL){
            s.push(p->val);
            p = p->next;
        }
        while (!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

int main() {
    char a[100] = "We Are Happy";
    Solution s;
    s.replaceSpace(a, 12);
    cout << a;
}

/*
3 4
1 4 7 8
2 6 8 9
6 10 12 20
 */