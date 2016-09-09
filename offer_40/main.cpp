#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;
using std::queue;
using std::stack;


//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return ;
        int flag = 1;
        int t = 0;
        for(int i = 0; i < data.size(); i++)
            t ^= data[i];
        while((t & flag) == 0) flag <<= 1;
        *num1 = t;
        *num2 = t;
        for(int i = 0; i < data.size(); i++){
            if(data[i] & flag){
                *num1 ^= data[i];
            }else{
                *num2 ^= data[i];
            }
        }
    }
};

int main(){
    Solution *s = new Solution();

}
