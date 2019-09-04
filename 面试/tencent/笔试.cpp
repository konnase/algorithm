//
//  笔试.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/4/7.
//  Copyright © 2019 李青坪. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define MAXN 10000
#define NIL -1
using namespace std;

int n;

int main(){
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 0;
    for (int i =0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        else if (a[i] > 0) {
            for (int j = i+1; j < n; ++j) {
                if (a[j] < 0) {
                    if (a[i] + a[j] > 0) {
                        count += a[j] * (i-j);
                        a[i] += a[j];
                        a[j] = 0;
                    }
                    else if (a[i] + a[j] == 0) {
                        count += a[j] * (i-j);
                        a[i] = 0;
                        a[j] = 0;
                        break;
                    }
                    else {
                        count += a[i] *(j - i);
                        a[i] = 0;
                        a[j] += a[i];
                        break;
                    }
                }
            }
        }
        else if (a[i] < 0){
            for (int j = i+1; j < n; ++j) {
                if (a[j] > 0) {
                    if (a[i] + a[j] < 0) {
                        count += a[j] * (j-i);
                        a[i] += a[j];
                        a[j] = 0;
                    }
                    else if (a[i] + a[j] == 0){
                        count += a[j] * (j-i);
                        a[i] = 0;
                        a[j] = 0;
                        break;
                    }
                    else {
                        count += a[i] * (i-j);
                        a[i] = 0;
                        a[j] += a[i];
                        break;
                    }
                }
            }
        }
    }
    cout << count << endl;
}

/*
5
5 -4 1 -3 1
 
6
5 4 3 -4 -3 -5
 */
