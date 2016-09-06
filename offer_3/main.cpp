#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> v;
        stack<int> s;
        if(head == NULL) return v;
        struct ListNode* t = head;
        while(t){
            s.push(t->val);
            t = t->next;
        }
        while(!s.empty()){
            int a = s.top();
            v.push_back(a);
            s.pop();
        }
        return v;
    }
};

struct ListNode *init_in(struct ListNode *head){
    int in;
    struct ListNode *tmp, *tmp1;
    cout << "Input nums:(end by 0)" << endl;
    cin >> in;
    tmp = new ListNode(in);
    head = tmp;
    while(cin >> in, in){
        tmp1 = new ListNode(in);
        tmp->next = tmp1;
        tmp = tmp1;
    }
    cout << "Input end" << endl;
    return head;
}
int main(){
    Solution *s = new Solution();
    struct ListNode* root = NULL;
    root = init_in(root);
    vector<int> v = s->printListFromTailToHead(root);
    vector<int>::iterator iter = v.begin();
    while(!v.empty()){
        cout << v.front() << endl;
        v.erase(v.begin());
    }
}
