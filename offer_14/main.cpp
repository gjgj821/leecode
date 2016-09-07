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
// 输入一个链表，输出该链表中倒数第k个结点。
class Solution{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL) return NULL;
        if(k == 0) return 0;
        ListNode *root, *node;
        int i = 1;
        root = revese(pListHead);
        node = root;
        while(i<k){
            node = node->next;
            i++;
        }
        revese(root);
        return node;
    }
private:
    ListNode * revese(ListNode* n){
        ListNode *pre = NULL, *last;
        while(n){
            last = n->next;
            n->next = pre;
            pre = n;
            n = last;
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
    head = s->FindKthToTail(head, 2);
    if(head) cout << head->val << endl;
}
