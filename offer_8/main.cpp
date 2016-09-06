#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int jumpFloor(int number) {
       if(number <= 2) return number;
       return jumpFloor(number - 1) + jumpFloor(number - 2); 
    }
};

int main(){
    Solution *s = new Solution();
    int m = s->jumpFloor(5);
    cout << m << endl;
}
