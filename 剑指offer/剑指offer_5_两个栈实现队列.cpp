//
// Created by 李青坪 on 2019/2/6.
//

#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void push(int node) {
        // 将stack1作为队列
        if (stack1.empty() && stack2.empty()){
            stack1.push(node);
        } else {
            stack2.push(node);
        }
    }

    int pop() {
        if (!stack1.empty()){
            int result = stack1.top();
            stack1.pop();
            return result;
        } else {
            if (stack2.empty()){
                return -1;
            } else {
                while (!stack2.empty()){
                    stack1.push(stack2.top());
                    stack2.pop();
                }
                int result = stack1.top();
                stack1.pop();
                return result;
            }
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution s;
    int value;
    for (int i = 0; i < 10; ++i) {
        cin >> value;
        if (value == -1){
            cout<< s.pop()<< " ";
        } else {
            s.push(value);
        }
    }
}