//
//  剑指offer_19_顺时针打印矩阵.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/8.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#define MAXN 10000
#define NIL -1
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        int n = matrix.size();
        int m = matrix[0].size();
        if (n == 1) {
            return matrix[0];
        }
        int i = 0, j = 0, direct = 0;
        int maxI = 0, maxJ = 0, minI = 1, minJ = 0;
        bool readyToStop = false;
        while (1) {
            if (direct ==0) {
                for (j = minJ; j <= m-1-maxJ; ++j) {
                    result.push_back(matrix[i][j]);
                }
                direct = 1;
                maxJ++;
                j--;
            } else if (direct == 1) {
                for (i = minI; i <= n-1-maxI; ++i) {
                    result.push_back(matrix[i][j]);
                }
                direct = 2;
                maxI++;
                i--;
            } else if (direct == 2) {
                for (j = m-1-maxJ; j >= minJ; --j) {
                    result.push_back(matrix[i][j]);
                }
                direct = 3;
                minJ++;
                j++;
            } else if (direct == 3) {
                for (i = n-1-maxI; i >= minI; --i) {
                    result.push_back(matrix[i][j]);
                }
                direct = 0;
                minI++;
                i++;
            }
            if (readyToStop) {
                break;
            }
            if (minI + maxI == n || minJ + maxJ == m) {
                readyToStop = true;
            }
        }
        return result;
    }
};

int n;

int main(){
    Solution s;
    int n = 4;
    vector<vector<int>> v;
    int count = 1;
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < 4; ++j) {
            temp.push_back(count++);
        }
        v.push_back(temp);
    }
    vector<int> result = s.printMatrix(v);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
