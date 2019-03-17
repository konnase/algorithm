//
// Created by 李青坪 on 2019/2/22.
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
    int NumberOf1(int n) {
        int count = 0;
        int p = 1;
        while (p != 0) {
            if ((p & n) != 0)
                ++count;
            p = p << 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << endl << s.NumberOf1(-2);
}