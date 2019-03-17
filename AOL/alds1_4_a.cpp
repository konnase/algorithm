//
// Created by 李青坪 on 2018/10/5.
//


#include <cstdio>
#include <set>
#include "cstring"

using namespace std;

int main(){
    int n, q;
    int S[10000];
    int T[500];
    memset(S, -1, sizeof(S));
    memset(T, -1, sizeof(T));
    scanf("%d", &n);
    for (int k = 0; k < n; ++k) {
        scanf("%d", &S[k]);
    }
    scanf("%d", &q);
    for (int l = 0; l < q; ++l) {
        scanf("%d", &T[l]);
    }
    set<int > flag;
    for (int j = 0; j < 10000; ++j) {
        if (S[j] < 0) break;
        flag.insert(S[j]);
    }
    int count = 0;
    for (int i = 0; i < 500; ++i) {
        if (T[i] < 0) break;
        if (flag.find(T[i]) != flag.end()) ++count;
    }
    printf("%d\n", count);
}