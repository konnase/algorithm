//
// Created by 李青坪 on 2019/2/21.
//

#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

typedef long long ll;

class Solution {
public:
    /*
     * 简单化简
     * f(n) = f(n-1) + f(n-2) + ... + f(0)
     * f(n-1) = f(n-2) + f(n-3) + ... +  f(0)
     * 得f(n) = f(n-1) + f(n-1) = 2 * f(n-1)
     */
    int jumpFloorII(int number) {
        if (number == 0) return 1;
        if (number == 1) return 1;
        int f[number + 1];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= number; ++i) {
//            int temp = 0;
//            for (int j = i - 1; j >= 0; --j) {
//                temp += f[j];
//            }
//            f[i] = temp;
            f[i] = 2 * f[i - 1];
        }
        return f[number];
    }

    int shiftJump(int number) {
        if (number == 0) return 1;
        return 1 << (number - 1);
    }
};

int main() {
    Solution s;
    cout << endl << s.shiftJump(1);
}