//
// Created by 李青坪 on 2019/1/29.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 10000
#define NIL -1
using namespace std;

int n, m;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); i++) {
            if (binary_search(array[i].begin(), array[i].end(), target)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<int > > arr;
    for (int i = 0; i < n; ++i) {
        int a;
        vector<int> b;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a);
            b.push_back(a);
        }
        arr.push_back(b);
    }
    Solution s;
    printf("%d", s.Find(19, arr));
}

/*
3 4
1 4 7 8
2 6 8 9
6 10 12 20
 */