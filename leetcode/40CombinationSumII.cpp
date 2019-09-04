//
//  40CombinationSumII.cpp
//  algorithm
//
//  Created by 李青坪 on 2019/3/23.
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
private:
    vector<int> cand;
public:
    vector<vector<int>*> finds(int target, int k) {
        target -= cand[k];
        if (target < 0) {
            return vector<vector<int>*>();
        }
        else if (target == 0) {
            vector<int>* re = new vector<int>({cand[k]});
            return vector<vector<int>*>({re});
        }
        else{
            vector<vector<int>*> result;
            for (int i = k+1; i < cand.size(); ++i) {
                if (i > k+1 && cand[i] == cand[i-1]) continue;
                vector<vector<int>*> temp = finds(target, i);
                for (auto item : temp) {
                    if (!(*item).empty()) {
                        (*item).push_back(cand[k]);
                    }
                }
                result.insert(result.end(), temp.begin(), temp.end());
            }
            return result;
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        sort(candidates.begin(), candidates.end());
        if (len == 0) {
            return vector<vector<int>>();
        }
        cand = candidates;
        set<vector<int>> semiResult;
        vector<vector<int>> result;
        for (int i = 0; i < len; ++i) {
            if (i > 0 && cand[i] == cand[i-1]) {
                continue;
            }
            vector<vector<int>*> temp = finds(target, i);
            for (auto item : temp) {
                vector<int> ints;
                for (int j = (*item).size()-1; j >= 0; --j) {
                    ints.push_back((*item)[j]);
                }
                semiResult.insert(ints);
            }
        }
        for (auto item : semiResult){
            result.push_back(item);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> pushV{10,1,2,7,6,1,5};
    
    vector<vector<int>> result = s.combinationSum2(pushV, 8);
    for (auto item : result) {
        for (auto ints : item) {
            cout << ints << " ";
        }
        cout << endl;
    }
}
