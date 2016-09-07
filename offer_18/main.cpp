#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};
// 操作给定的二叉树，将其变换为源二叉树的镜像。
class Solution{
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL) return ;
        if(pRoot->left == NULL && pRoot->right){
            pRoot->left = pRoot->right;
            pRoot->right = NULL;
        }else if(pRoot->right == NULL && pRoot->left){
            pRoot->right = pRoot->left;
            pRoot->left = NULL;
        }else if(pRoot->right && pRoot->left){
            TreeNode* t = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = t;
        }
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};


int main(){
    Solution *s = new Solution();
    //ListNode *head1 = NULL, *head2 = NULL;
    //head1 = init(head1);
    //head2 = init(head2);
    //head1 = s->HasSubtree(head1, head2);

}
