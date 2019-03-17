//
// Created by 李青坪 on 2018/10/30.
//

#include <iostream>
#define MAXM 1000000000
#define MAXN 100000

using namespace std;

typedef long long ll;
int n, m;
ll MAXINT = 1000000000000;

int coin[MAXN+1];
ll cnt[MAXN+1];

int calculate(int m) {
    fill(cnt, cnt+n, MAXINT);
    for (int i = 1; i <= n; ++i) {
        ll temp = m/coin[i];
        cnt[i] = min(cnt[i-1], temp == m ? temp : temp+1);
    }
    return cnt[n];
}

int main(){
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i <= n; ++i) {
        coin[i] = i;
    }
    cout << calculate(m) << endl;
}
