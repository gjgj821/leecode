#include <iostream>
#include <vector>
using namespace std;


// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
class Solution{
public:
    void push(int value) {

    }
    void pop() {

    }
    int top() {

    }
    int min() {

    }
};


int main(){
    Solution *s = new Solution();
    int in;
    while(cin >> in && in){
        s->push(in);
    }
    s->pop();
    cout << "top:" << s->top() << endl;
    cout << "min:" << s->min() << endl;
}
