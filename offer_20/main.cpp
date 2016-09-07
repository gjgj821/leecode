#include <iostream>
#include <stack>
using namespace std;


// 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
#define MIN(a, b) ((a) < (b) ? (a) : (b))
class Solution {
    stack<pair<int, int> > s;
public:
    void push(int value) {
        s.push(pair<int, int>(value, s.empty() ? value : MIN(value, min())));
    }
    void pop() {
        s.pop();
    }
    int top() {
        return s.top().first;
    }
    int min() {
        return s.top().second;
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
