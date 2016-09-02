#include <iostream>
using namespace std;

struct node{
    int value;
    struct node *next;
};

struct node *init_in(struct node *head){
    int in;
    struct node *tmp, *tmp1;
    cout << "Input nums:(end by 0)" << endl;
    cin >> in;
    tmp = new node();
    tmp->value = in;
    tmp->next = NULL;
    head = tmp;
    while(cin >> in, in){
        tmp1 = new node();
        tmp1->value = in;
        tmp1->next = NULL;
        tmp->next = tmp1;
        tmp = tmp1;
    }
    cout << "Input end" << endl;
    return head;
}

struct node* reverse(struct node *n){
    struct node *tmp1, *tmp2 = NULL;
    while(n){
        tmp1 = n->next;
        n->next = tmp2;
        tmp2 = n;
        n = tmp1;
    }
    return tmp2;
}

struct node* reverse_r(struct node *n, struct node *prev){
    struct node *tmp;
    if(n){
        tmp = n->next;
        n->next = prev;
        return reverse_r(tmp, n);
    }else{
        return prev;
    }
}

void print_node(struct node *head){
    struct node *tmp = head;
    while(tmp){
        cout << tmp->value << ',';
        tmp = tmp->next;
    }
    cout << endl;
}


int main(){
    struct node *first;
    first = init_in(first);
    print_node(first);
    first = reverse(first);
    print_node(first);
    first = reverse_r(first, NULL);
    print_node(first);
}
