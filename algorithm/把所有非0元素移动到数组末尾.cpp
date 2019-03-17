//
//  把所有非0元素移动到数组末尾.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/13.
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

int findNext(int j, int a[], int n) {
    while (j < n) {
        if (a[j] == 0) {
            ++j;
        } else {
            break;
        }
    }
    return j;
}

void moveZeroElement(int a[], int n){
    int i = 0;
    int j = findNext(0, a, n);
    while (j < n) {
        a[i] = a[j];
        j = findNext(j+1, a, n);
        ++i;
    }
    while (i < n) {
        a[i] = 0;
        ++i;
    }
}

int main(){
    int a[] = {0,3,4,5,0,0,0,34,2,0};
    int n = sizeof(a) / 4;
    moveZeroElement(a, n);
    for (auto i : a) {
        cout << i << " ";
    }
}
