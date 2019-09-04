//
// Created by 李青坪 on 2018/10/5.
//

#include "cstdio"
#include "iostream"
#include "vector"

using namespace std;

int cmp(int a, int b){
    if (a == b) return 0;
    else return a > b ? 1: -1;
}
int binarySearch(int S[], int size, int key){
    int high = size - 1;
    int low = 0;
    int mid = (high + low)/2;
    while (low <= high){
        if (cmp(S[mid], key) == -1){
            low = mid + 1;
        } else if (cmp(S[mid], key)){
            high = mid - 1;
        } else return 1;
        mid = (high + low )/2;
    }
    return 0;
}


int main(){
    int n, q;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &S[i]);
    }
    scanf("%d", &q);
    int key, count = 0;
    for (int j = 0; j < q; ++j) {
        scanf("%d", &key);
        if (binarySearch(S, n, key)) ++count;
    }
    printf("%d\n", count);
}

/*
3
1 2 3
1
5
 */