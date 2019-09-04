//
// Created by 李青坪 on 2018/10/27.
//

#include <cstdio>
#include <string>
#include <iostream>
#define MAXN 2000001
using namespace std;

int pQueue[MAXN];
int H = 0; // 记录优先级队列中有多少个结点了

void exchange(int i, int j){
    int temp = pQueue[i];
    pQueue[i] = pQueue[j];
    pQueue[j] = temp;
}

void insert(int value){
    ++H;
    pQueue[H] = value;
    int i = H;
    while (i/2 > 0){
        if (pQueue[i] > pQueue[i/2]){
            exchange(i, i/2);
        }
        i /= 2;
    }
}

int maxHeapJudge(int i){
    int l = i*2;
    int r = l+1;
    int largest = i;
    if (l <= H && pQueue[l] > pQueue[i]){
        largest = l;
    }
    if (r <= H && pQueue[r] > pQueue[largest]){
        largest = r;
    }
    if (largest != i){
        exchange(i, largest);
        maxHeapJudge(largest);
    }
}

int extract(){
    if (H < 1) return -1;
    int max = pQueue[1];
    pQueue[1] = pQueue[H];
    --H;
    maxHeapJudge(1);
    return max;
}

int main(){
    string command;
    cin >> command;
    int value;
    while (command != "end"){
        if (command == "insert"){
            scanf("%d", &value);
            insert(value);
        } else if (command == "extract"){
            printf("%d\n", extract());
        }
        cin >> command;
    }
}
/*
insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end

 */