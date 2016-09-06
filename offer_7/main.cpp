#include <iostream>
#include <vector>
using namespace std;

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
