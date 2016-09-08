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


// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        stack<TreeNode *> s;
        TreeNode *node = pRootOfTree;
        TreeNode *root = NULL, *last = NULL;
        while(node || s.size()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top();s.pop();
            if(root == NULL){
                root = node;
                last = node;
            }else{
                last->right = node;
                node->left = last;
                last = node;
            }
            node = node->right;
        }
        return root;
    } 
};

int main(){
    Solution *s = new Solution();

}
