//
//  剑指offer_28_数组中出现次数超过一半的数字.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/17.
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

class Solution {
public:
    /*
     链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
     来源：牛客网
     
     如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
     在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
     */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int num = numbers[0], count = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (num == numbers[i]) {
                ++count;
                continue;
            }
            --count;
            if (count == 0) {
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            if (num == numbers[i]) {
                ++count;
            }
        }
        return count > numbers.size() / 2 ? num : 0;
    }
};

int main(){
    Solution s;
    vector<int> pushV{4,3,7,4,10,4,5,4,4,1};

    cout << s.MoreThanHalfNum_Solution(pushV);
}
