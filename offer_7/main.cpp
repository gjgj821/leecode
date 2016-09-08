#include <iostream>
#include <vector>
using namespace std;

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
//n<=39
class Solution{
public:
    int Fibonacci(int n) {
        int f0 = 0, f1 = 1;
        while(n--){
            f1 += f0;
            f0 = f1 - f0;
        }
        return f0;

    }
};

int main(){
    Solution *s = new Solution();
    int m = s->Fibonacci(5);
    cout << m << endl;
}
