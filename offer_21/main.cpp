#include <iostream>
#include <vector>
#include <stack>
using namespace std;


//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int size = pushV.size();
        stack<int> s;
        for(int i = 0, j = 0; i < size; i++){
            s.push(pushV[i]);
            while(!s.empty() && popV[j] == s.top()){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};


int main(){
    Solution *s = new Solution();
    int a[][5] = {{1,2,3,4,5}, {4,5,3,2,1}};
    vector<int> p1(a[0], a[0]+5);
    vector<int> p2(a[1], a[1]+5);
    cout << s->IsPopOrder(p1, p2) << endl;
}