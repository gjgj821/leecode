#include <iostream>
using namespace std;

#define HEIGHT(N) (N == NULL ? 0 : N->height)
#define MAX(A, B) (A > B ? A : B)

struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
};

struct node *left_rotate(struct node *n){
    struct node *tmp = n->left;
    n->left = tmp->right;
    tmp->right = n;

    n->height = MAX(HEIGHT(n->left), HEIGHT(n->right)) + 1;
    tmp->height = MAX(HEIGHT(tmp->left), HEIGHT(tmp->right)) + 1;

    return tmp;
}

struct node *right_rotate(struct node *n){
    struct node *tmp = n->right;
    n->right = tmp->left;
    tmp->left = n;

    n->height = MAX(HEIGHT(n->left), HEIGHT(n->right)) + 1;
    tmp->height = MAX(HEIGHT(tmp->left), HEIGHT(tmp->right)) + 1;

    return tmp;
}

inline struct node * left_right_rotate(struct node *n){
    n->right = left_rotate(n->right);
    return right_rotate(n);
}

inline struct node * right_left_rotate(struct node *n){
    n->left = right_rotate(n->left);
    return left_rotate(n);
}

struct node * insert_node(struct node *root, struct node *now){
    if(root == NULL) return now;
    if(root->value > now->value){
        root->right = insert_node(root->right, now);
        if(HEIGHT(root->right) - HEIGHT(root->left) == 2){
            if(root->right->value < now->value){
                right_rotate(root);
            }else{
                left_right_rotate(root);
            }
        }
    }else if(root->value < now->value){
        root->left = insert_node(root->left, now);
        if(HEIGHT(root->left) - HEIGHT(root->right) == 2){
            if(root->left->value > now->value){
                left_rotate(root);
            }else{
                right_left_rotate(root);
            }
        }
    }
    root->height = MAX(HEIGHT(root->left), HEIGHT(root->right));
    return root;
}

struct node *init_tree(struct node *root){
    int in;
    struct node *tmp;
    cout << "Input nums:(end by 0)" << endl;
    cin >> in;
    root = new node();
    root->value = in;
    root->height = 0;
    root->left = NULL;
    root->right = NULL;
    while(cin >> in, in){
        tmp = new node();
        tmp->value = in;
        tmp->height = 0;
        tmp->left = NULL;
        tmp->right = NULL;
        insert_node(root, tmp);
    }
    cout << "Input end" << endl;
    return root;
}

int tree_depth(struct node *root){
    if(root == NULL) return 0;
    int left_depth = tree_depth(root->left);
    int right_depth = tree_depth(root->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

bool is_balance1(struct node *root){
    if(root == NULL) return 0;
    int left_depth = tree_depth(root->left);
    int right_depth = tree_depth(root->right);
    int diff = left_depth - right_depth;
    if(diff > 1 || diff < -1) return false;

    return is_balance1(root->left) && is_balance1(root->right);
}

bool is_balance(struct node *root, int *depth){
    if(root == NULL) return true;
    int left_depth, right_depth;
    bool b = is_balance(root->left, &left_depth);
    if(!b) return false;
    b = is_balance(root->right, &right_depth);
    if(!b) return false;

    int diff = left_depth - right_depth;
    if(diff > 1 || diff < -1) return false;
    *depth = 1 + max(left_depth, right_depth);
    return true;
}

void print_tree(struct node *root){
    if(root == NULL) return;
    cout << root->value;
    print_tree(root->left);
    print_tree(root->right);
    cout << endl;
}


class Single{
    public:
        static Single * instance();
    private:
        Single();
        ~Single();
        static Single * _instance;
};

inline Single * Single::instance(){
    if(_instance == NULL){
        _instance = new Single();
    }
    return _instance;
}

int main(){
    struct node *root = NULL;
    init_tree(root);
    print_tree(root);
    int h = 0;
    cout << "is balance:" << is_balance(root, &h) << endl;
    cout << "is balance1:" << is_balance1(root) << endl;

}
