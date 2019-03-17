//
//  tencent3.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//
//排列组合

#include <iostream>
#include <algorithm>
#define MAX 100000000
using namespace std;

typedef long long ll;


int main(){
    int n,s;
    cin >> n >> s;
    ll up = 1, down = 1;
    for (int i = 0; i < s; ++i) {
        up *= (n-i);
        down *= (i+1);
    }
    ll result = up/down * (n-s+1);
    cout << result % 1000000007 << endl;
}
