#include <iostream>
#include <vector>
using namespace std;


// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
class Solution{
public:
    double Power(double base, int exponent) {
        if(exponent > 0){
            return power_positive(base, exponent);
        }else{
            return power_negative(base, exponent);
        }
    }
private:
    double power_positive(double base, int exponent){
        if(exponent == 0) return 1;
        return base * power_positive(base, exponent - 1);
    }
    double power_negative(double base, int exponent){
        if(exponent == 0) return 1;
        return power_negative(base, exponent + 1) / base;
    }
};

int main(){
    Solution *s = new Solution();
    double d = s->Power(1.1, 3);
    cout << d << endl;
}
