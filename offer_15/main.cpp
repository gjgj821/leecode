#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
//输入一个链表，反转链表后，输出链表的所有元素
class Solution{
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre = NULL, *last;
        while(pHead){
            last = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = last;
        }
        return pre;
    }
};

ListNode * init(ListNode *head){
    int in = 0;
    cin >> in;
    ListNode *n = new ListNode(in);
    head = n;
    while(cin >> in && in){
        ListNode *tmp = new ListNode(in);
        n->next = tmp;
        n = tmp;
    }
    return head;
}

int main(){
    Solution *s = new Solution();
    ListNode *head = NULL;
    head = init(head);
    head = s->ReverseList(head);
    while(head){
        cout << head->val << endl;
        head = head->next;
    }
}
