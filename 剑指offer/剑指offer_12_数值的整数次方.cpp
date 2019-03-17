//
// Created by 李青坪 on 2019/2/23.
//

#include <cstdlib>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    /*
     * 按位与操作
     */
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        if (exponent == 1) return base;
        int n = abs(exponent);
        double result = 1, tmp = base;
        while (n != 0) {
            if ((n & 1) == 1) {
                result *= tmp;
            }
            n = n >> 1;
            tmp *= tmp;
        }

        return exponent > 0 ? result : 1 / result;
    }
};

int main() {
    Solution s;
    cout << endl << s.Power(2.0, 6);
}