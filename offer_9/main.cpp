#include <iostream>
#include <vector>
using namespace std;

//每个台阶都有跳与不跳两种情况（除了最后一个台阶），最后一个台阶必须跳。所以共用2^(n-1)中情况
class Solution{
public:
    int jumpFloorII(int number) {
       if (number <= 0) {
            return -1;
        } else if (number == 1) {
            return 1;
        } else {
            return 2 * jumpFloorII(number - 1);
        } 
    }
};

int main(){
    Solution *s = new Solution();
    int m = s->jumpFloorII(5);
    cout << m << endl;
}
