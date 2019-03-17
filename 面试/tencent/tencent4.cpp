//
//  tencent4.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100000000
using namespace std;

typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int result[n];
    fill(result, result+n, MAX);
    for (int i = 0; i < n-m; ++i) {
        bool visit[m+1];
        fill(visit, visit+m+1, false);
        int count = 0;
        for (int j = i; j < n; ++j) {
            if (!visit[a[j]]) {
                visit[a[j]] = true;
                count++;
            }
            if (count == m) {
                result[i] = j - i + 1;
                break;
            }
        }
    }
    int mins = MAX;
    for (int i = 0; i<n; ++i) {
        mins = min(mins, result[i]);
    }
    cout << mins <<endl;
}
/*
12 5
3 5 4 3 1 3 2 4 3 1 4 5
 */
