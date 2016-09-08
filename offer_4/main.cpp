#include <iostream>
#include <queue>
using namespace std;

struct node{
    int value;
    struct node *left;
    struct node *right;
};
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回
/**
 * PreOrder(T)=T的根节点+PreOrder(T的左子树)+PreOrder(T的右子树) 
 * InOrder(T)=InOrder(T的左子树)+T的根节点+InOrder(T的右子树) 
 * PostOrder(T)=PostOrder(T的左子树)+PostOrder(T的右子树)+T的根节点
 * 先获取前序第一个值为根节点，获取该值在中序中的索引
 * 根据索引获取中序中左边树（右边树）的中序，根据长度获取前序中左边树（右边树）的前序
 * 递归获取所有节点树
 */
struct node* build_tree(int *pre_list, int *in_list, int n){
    if(n == 0) return NULL;
    struct node* root = new struct node();
    root->value = pre_list[0];
    int left, right, i = 0;
    for(i = 0; i < n && in_list[i] != pre_list[0]; i++);
    left = i;
    right = n - i - 1; 
    root->left = build_tree(&pre_list[1], &in_list[0], left);
    root->right = build_tree(&pre_list[left + 1], &in_list[left + 1], right);
    return root;
}

void print_tree(struct node *root){
    if(root == NULL) return;
    queue<struct node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){  
        struct node *p = q.front();
        q.pop();
        if(p == NULL){
            cout << " " << endl;
            continue;
        }else{
            cout << p->value << " ";
        }
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
        q.push(NULL);
    }
}


int main(){
    int pre_list[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in_list[] = {4, 7, 2, 1, 5, 3, 8, 6};
    struct node* root = build_tree(pre_list, in_list, 8);
    print_tree(root);
}
