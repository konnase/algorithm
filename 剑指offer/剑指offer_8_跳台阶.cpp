//
// Created by 李青坪 on 2019/2/19.
//

#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

typedef long long ll;

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 0 || number == 1) return 1;
        ll result = 0;
        ll half = number / 2;
        for (ll i = 0; i <= half; ++i) {
            ll up = 1;
            ll down = 1;
            for (ll j = 1; j <= i; ++j) {
                up *= (number - i - j + 1);
                down *= j;
            }
            cout<<up<<" ";
            result += (up / down);
        }
        return result;
    }

    /*
     * 第一次跳一格，剩下n-1格；跳两格，剩下n-2格；f(n) = f(n-1) + f(n-2)：斐波那契数列
     */
    int fibonacciJump(int number){
        if (number == 1) return 1;
        if (number == 2) return 2;
        ll f1 = 1;
        ll f2 = 2;
        for (int i = 3; i <= number; ++i) {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f2;
    }

};

int main() {
    Solution s;
    cout <<endl<< s.fibonacciJump(29);
}