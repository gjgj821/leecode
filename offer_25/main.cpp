#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};


// 输入一个复杂链表（每个节点中有节点值，以及两个指针，
// 一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == NULL) return NULL;
        RandomListNode *head = pHead;
        while(head){
            RandomListNode *node = new RandomListNode(head->label);
            node->next = head->next;
            head->next = node;
            head = node;
        }
        head = pHead;
        while(head){
            RandomListNode *node = head->next;
            if(head->random){
                // random->next 
                node->random = head->random->next;
            }
            head = node->next;
        }
        RandomListNode *root = pHead->next;
        head = pHead;
        RandomListNode *tmp;
        while(head->next){
            tmp = head->next;
            head->next = tmp->next;
            head = tmp;
        }
        return root;
    }
};

int main(){
    Solution *s = new Solution();

}
