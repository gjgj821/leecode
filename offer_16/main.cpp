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
// 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则
class Solution{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL) return pHead2;
        if(pHead2 == NULL) return pHead1;
        ListNode *head = pHead1->val < pHead2->val ? pHead1 : pHead2;
        ListNode *now = new ListNode(0);
        ListNode *e = now;
        while(pHead1 || pHead2){
            if(pHead1 == NULL){
                now->next = pHead2;
                pHead2 = pHead2->next;
            }else if(pHead2 == NULL){
                now->next = pHead1;
                pHead1 = pHead1->next;
            }else if(pHead1->val < pHead2->val){
                now->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                now->next = pHead2;
                pHead2 = pHead2->next;
            }
            now = now->next;
        }
        delete e;
        return head;
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
    ListNode *head1 = NULL, *head2 = NULL;
    head1 = init(head1);
    head2 = init(head2);
    head1 = s->Merge(head1, head2);
    while(head1){
        cout << head1->val << endl;
        head1 = head1->next;
    }
}
