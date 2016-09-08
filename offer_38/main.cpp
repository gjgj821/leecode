#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::vector;
using std::queue;
using std::stack;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    
    } 
};

int main(){
    Solution *s = new Solution();

}
