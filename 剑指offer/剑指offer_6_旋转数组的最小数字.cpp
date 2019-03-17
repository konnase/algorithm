//
// Created by 李青坪 on 2019/2/12.
//

#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        for (int i = 1; i < rotateArray.size() - 1; ++i) {
            if (rotateArray[i] < rotateArray[i - 1]) {
                return rotateArray[i];
            }
        }
        return rotateArray[0];
    }

    /*
     * 时间复杂度为O(logn)，二分查找
     */
    int anotherSol(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        int left = 0, right = rotateArray.size() - 1;
        while (left < right - 1) {
            int mid = (left + right) / 2;
            if (rotateArray[mid] > rotateArray[left]) {
                left = mid;
            } else if (rotateArray[mid] < rotateArray[left]) {
                right = mid;
            } else if (rotateArray[mid] == rotateArray[left]) {
                left += 1;
            }
        }
//        cout << left << " " << right << endl;
        return min(rotateArray[left], rotateArray[right]);
    }
};

int main() {
    Solution s;
    vector<int> r;
    int a[] = {6501, 6828, 6963, 7036, 7422, 7674, 8146, 8468, 8704, 8717, 9170,
               9359, 9719, 9895, 9896, 9913, 9962, 154, 293, 334, 492, 1323,
               1479, 1539, 1727, 1870, 1943, 2383, 2392, 2996, 3282, 3812, 3903,
               4465, 4605, 4665, 4772, 4828, 5142, 5437, 5448, 5668, 5706, 5725, 6300, 6335};
//    int a[] = {};
    int value;
    for (int i : a) {
        value = i;
        r.push_back(value);
    }
    cout << s.anotherSol(r) << endl;
}

/*
3 4 5 1 2

1 0 1 1 1
 */