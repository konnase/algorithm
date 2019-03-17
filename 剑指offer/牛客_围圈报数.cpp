//
// Created by 李青坪 on 2019/2/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n = 5;

int main() {
    int a[n];
    fill(a, a + n, 1);
    int result = 0;
    int count = 0, remain = n;
    int i = 0;
    while (true) {
        if (a[i] == 1) {
            ++count;
            if (count % 2 == 0) {
                a[i] = 0;
                result = i + 1;
                --remain;
            }
        }
        if (remain == 1) break;
        i = (i + 1) % n;
    }
    cout << result << endl;
//    for (int j = 0; j < n; ++j) {
//        if (a[j] == 1)
//            cout << j+1 << endl;
//    }
}