//
//  tencent2.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/9.
//  Copyright © 2019 李青坪. All rights reserved.
//
// -1 2 -3 4 -5 6...
// 求[l, r]区间和

#include <iostream>

using namespace std;

int q;


int main(){
    cin >> q;
    int l, r, result;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        if (l % 2 == 0 && r%2 == 0) {
            result = (r-l)/2*(-1) + r;
        } else if (l % 2 == 0 && r % 2 !=0){
            result = (1 + (r - l)/2) * -1;
        } else if (l %2 != 0 && r %2 == 0) {
            result = (1 + (r-l)/2);
        } else if (l % 2 != 0 && r %2 != 0) {
            result = ((r-l)/2) -r;
        }
        cout << result << endl;
    }
}
