#include <iostream>
#include <stack>
using namespace std;

class Solution{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size()){
            int n = stack2.top();
            stack2.pop();
            return n;
        }else if(stack1.empty()){
            return 0;
        }else{
            while(stack1.size()){
                int n = stack1.top();
                stack1.pop();
                stack2.push(n);
            }
            return pop();
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


int main(){
    Solution *s = new Solution();
    int in = 0;
    while(cin >> in && in){
        s->push(in);
    }
    cout << "Input end";
    while((in = s->pop())){
        cout << in << endl;
    }
}
