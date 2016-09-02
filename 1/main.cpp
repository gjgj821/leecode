#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {

public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> rmap;
        int i, n, diff;
        for(i = 0; i < nums.size(); i++){
            diff = target - nums[i];
            if(!rmap.count(nums[i])){
                rmap.insert(pair<int, int>(nums[i], i));
            }
            if(rmap.count(diff)){
                n = rmap[diff];
                if(n != i){
                    result.push_back(n);
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }

};


int main(){
    int d[4] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(d, d+4);
    vector<int> abc;
    Solution *s = new Solution();
    abc = s->twoSum(nums, target);
    cout << abc[0] << ',' << abc[1] << '\n';
}
