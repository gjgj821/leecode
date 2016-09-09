#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using std::vector;
using std::queue;


//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
class Solution {
    vector<int> v;
public:
    void Insert(int num){
        v.push_back(num);
        std::sort(v.begin(), v.end());
    }

    double GetMedian(){
        int size = v.size();
        if(size & 1){
            return v[size >> 1];
        }else{
            int left = v[(size >> 1) - 1];
            int right = v[size >> 1];
            return (static_cast<double>(left) + right) / 2;
        }
    }

};

int main(){
    Solution *s = new Solution();

}
