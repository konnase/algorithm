//
// Created by 李青坪 on 2019/2/24.
//

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define MAXN 100000
#define NIL -1
using namespace std;

int n;
int a[MAXN];

int main() {
    do {
        cin >> n;
        ++a[n];
    } while (getchar() != '\n');
//    cout << a[0] << a[1] << a[3] << endl;
    int result = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (a[i] == 0) continue;
        if (a[i] == i) result += (i + 1);
        else if (a[i] < i) result += (i + 1);
        else {
            result += (i + 1);
            int t = a[i];
            while (t - (i + 1) > 0) {
                result += (i + 1);
                t -= (i + 1);
            }
        }
    }
    cout << result << endl;
}