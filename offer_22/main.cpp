#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> v;
        if(root == NULL) return v;
        q.push(root);
        while(q.size()){
            TreeNode *n = q.front();
            q.pop();
            v.push_back(n->val);
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        return v;
    }
};


int main(){
    Solution *s = new Solution();

}
