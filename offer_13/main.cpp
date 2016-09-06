#include <iostream>
#include <vector>
using namespace std;


// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
class Solution{
public:
    void reOrderArray(vector<int> &array) {
        
    } 
};

int main(){
    Solution *s = new Solution();
    int a[] = {1,5,6,2,54,76};
    vector<int> v(a, a+6);
    s->reorderArray(v);
    for(int i =0; i< v.size(); i++)
        cout << v[i] << endl;
}
