#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using std::vector;
using std::queue;
using std::deque;


//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
//针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> res;
        if(size == 0) return res;
        deque<int> dq;
        for(int i = 0; i < num.size(); i++){
            // 从后移除小于当前值的数
            while(dq.size() && num[dq.back()] < num[i]) dq.pop_back();
            // 将超过滑动窗口的数移除
            while(dq.size() && i - dq.front() + 1 < size) dq.pop_front();
            dq.push_back(i);
            if(i + 1 >= size)
                res.push_back(num[dq.front()]);
        }
        return res;
    }
};

int main(){
    Solution *s = new Solution();

}
