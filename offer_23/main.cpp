#include <iostream>
#include <vector>
#include <queue>
using  std::vector;

//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
class Solution {
    bool judge(vector<int> &a, int start, int end){
        if(end < 0) return true;
        int root = a[end];
        int r = end;
        while(r > start && a[r - 1] > root) r--;
        for(int j = r; j >= start; j--)
            if(a[j] > root)
                return false;
        return judge(a, start, r - 1) && judge(a, r, end - 1);
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        return judge(sequence, 0, size - 1);
    }
};


int main(){
    Solution *s = new Solution();
    vector<int> v;
    int in = 0;
    while(std::cin >> in && in){
        v.push_back(in);
    }
    std::cout << s->VerifySquenceOfBST(v) << std::endl;
}
