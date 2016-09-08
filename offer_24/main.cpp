#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
       val(x), left(NULL), right(NULL) {
    }
};

//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
class Solution {
public:
    void TreePath(TreeNode* root,int target,vector<int> &path,vector<vector<int> > &pathList){
        if(root == NULL)
            return ;
        path.push_back(root->val);
        bool isLeaf = root->left==NULL && root->right==NULL;
        if(root->val==target && isLeaf){
            pathList.push_back(path);
            path.pop_back();
        } else {
            TreePath(root->left,target - root->val,path,pathList);
            TreePath(root->right,target - root->val,path,pathList);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber){
        vector<vector<int> > FindPath;
        vector<int> Path;  // 为了保存每一次递归的值,这里声明了一个path
        if(root == NULL)
            return FindPath;
        TreePath(root,expectNumber,Path,FindPath);
        return FindPath;
    }
};

int main(){
    Solution *s = new Solution();

}
