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
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
class Solution{
public:
    bool HasSubtree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL) return false;
        if(pRoot1->val == pRoot2->val && equal(pRoot1, pRoot2)) return true;
        if(HasSubtree(pRoot1->left, pRoot2)) return true;
        if(HasSubtree(pRoot2->right, pRoot2)) return true;
        return false;
    }
private:
    bool equal(TreeNode* p1, TreeNode* p2){
        if(p1 == NULL && p2 == NULL) return true;
        if(p1 == NULL || p2 == NULL) return false;
        if(p1->val == p2->val){
            if(equal(p1->left, p2->left) && equal(p1->right, p2->right)) return true;
        }
        return false;
    }
};


int main(){
    Solution *s = new Solution();
    //ListNode *head1 = NULL, *head2 = NULL;
    //head1 = init(head1);
    //head2 = init(head2);
    //head1 = s->HasSubtree(head1, head2);

}
