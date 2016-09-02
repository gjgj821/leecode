#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* left, * right, * last;
        int sum;
        ListNode* head = new ListNode(0);
        last = head;
        left = l1;
        right = l2;
        while(left || right){
            if(left){
                sum += left->val;
                left = left->next;
            }
            if(right){
                sum += right->val;
                right = right->next;
            }
            last->next = new ListNode(sum % 10);
            last = last->next;
            sum /= 10;
        }
        if(sum){
            last->next = new ListNode(1);
        }
        return head->next;
    }
};


int main(){
    ListNode *l1, *l2, *first, *node;
    Solution *s = new Solution();
    int i1[3] = {2, 4, 3};
    int i2[3] = {5, 6, 4};
    int i;
    first = new ListNode(i1[0]);
    l1 = first;
    for(i = 1; i < 3; i++){
        node = new ListNode(i1[i]);
        first->next = node;
        first = node;
    }
    first = new ListNode(i2[0]);
    l2 = first;
    for(i = 1; i < 3; i++){
        node = new ListNode(i2[i]);
        first->next = node;
        first = node;
    }
    first = s->addTwoNumbers(l1, l2);
    while(first){
        cout << first->val << ',';
        first = first->next;
    }
    cout << '\n';
}
