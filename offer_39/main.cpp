#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;
using std::queue;
using std::stack;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
}

//输入一棵二叉树，判断该二叉树是否是平衡二叉树
class Solution {
    bool balance(TreeNode* root, int *depth){
        if(root == NULL) return true;
        int left_depth, right_depth;
        bool b = balance(root->left, &left_depth);
        if(!b) return false;
        b = balance(root->right, &right_depth);
        if(!b) return false;

        int diff = left_depth - right_depth;
        if(diff > 1 || diff < -1) return false;
        *depth = 1 + max(left_depth, right_depth);
        return true;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int d = 0;
        return balance(pRoot, &d);
    }
};

int main(){
    Solution *s = new Solution();

}
