//
// Created by 李青坪 on 2018/10/5.
//

#include "cstdio"

using namespace std;

int maxk = 100000;  //最大卡车数目
int maxw = 10000;   //单个货物最大重量
int goods[100000];

int search(int P, int n, int k){
    int sum = 0, numCarUsed = 0;
    for (int i = 0; i < n; ++i) {
        if (goods[i] > P ) return 0;
        if ((sum + goods[i] == P) && (i == n - 1)){
            return n;
        }
        if (sum + goods[i] >= P) {
            int temp = sum;
            sum = 0;
            ++numCarUsed;
            if (temp + goods[i] > P)
                sum += goods[i];
        }
        else {
            sum += goods[i];
        }
        if (numCarUsed >= k){
            return i; //最后几个货物还没装的情况下就已经把车用完了
        }
    }
    return n;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &goods[i]);
    }
    int low = 0;
    int high = maxk * maxw;
//    int low = 28;
//    int high = 56;  //238 59
    while ( high - low > 1){
        int mid = (low + high) /2;
        int numGoods = search(mid, n, k);
        if (numGoods == n) high = mid;
        else low = mid;
    }
    printf("%d\n", high);
}

/*
5 3
8
1
7
3
9
 */