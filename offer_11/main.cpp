#include <iostream>
#include <vector>
using namespace std;


// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
// n & n - 1:将最右位的1变为0，那有几位1就操作几次  
class Solution{
public:
    int NumberOf1(int n) {
       int t = 0;
       while(n!= 0){
           t++;
           n = n & (n - 1);
       } 
       return t;
    }
};

int main(){
    Solution *s = new Solution();
    int m = s->NumberOf1(5);
    cout << m << endl;
}
