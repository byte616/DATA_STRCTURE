#include<stdio.h>
#include<stdlib.h>
// tree's data
struct node{
    int data;
    struct node *left,*right;
}*head=NULL,*PRE=NULL,*q[505];
/*******QUEUE*******/
int top=-1,rear=-1;
int empty(){
    return rear==top;
}
void push(struct node *x){
    q[++rear]=x;
}
struct node *pop(){
    return q[++top];
}
/********END********/
// inorder: left -> mid -> right
void inorder(struct node* node){
    if(node){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}
// levelorder: BFS from the root
void levelorder(struct node* node){
    push(node);
    while(!empty()){
        struct node *u=pop();
        printf("%d ",u->data);
        if(u->left)push(u->left);
        if(u->right)push(u->right);
    }
}
// search function can help insert and delete
struct node* search(struct node *POS,int x){
    struct node *tmp=POS;
    if(!tmp)return NULL;
    if(tmp->data==x)return tmp;
    if(x>tmp->data){
        if(tmp->right){
            PRE=tmp;// record privous node to delete node
            return search(tmp->right,x);
        }
        else return tmp;// return previous node to insert node after
    }
    else{
        if(tmp->left){
            PRE=tmp;
            return search(tmp->left,x);
        }
        else return tmp;
    }
}
void insert(int x){
    struct node* tmp=search(head,x);// search its previous node
    if(tmp||!head){
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=x;
        new_node->left=new_node->right=NULL;
        if(head){// connect to previous node's left or right
            if(x>tmp->data)tmp->right=new_node;
            else tmp->left=new_node;
        }
        else head=new_node;// head has nothing, let head=new_node
    }
}
void _delete(int x){
    struct node* delete_node=search(head,x);// search the delete node
    // seperate into 4 case
    // 1. the node is leaf, delete it directively
    if(!delete_node->left&&!delete_node->right){
        // previous node's pointer=NULL
        if(PRE->data>x)PRE->left=NULL;
        else PRE->right=NULL;
        free(delete_node);// delete it
        return;
    }
    // 2.the node has only right child
    if(!delete_node->left){
        if(PRE->data>x)PRE->left=delete_node->right;
        PRE->right=delete_node->right;// connect the right subtree and previous node
        free(delete_node);
        return;
    }
    // 3. the node has only left child
    if(!delete_node->right){
        if(PRE->data>x)PRE->left=delete_node->left;
        else PRE->right=delete_node->left;// connect the left subtree and previous node
        free(delete_node);
        return;
    }
    // 4. both side have child
    // find right subtree's most smallest element E
    struct node* MID=delete_node->right;
    while(MID->left!=NULL)MID=MID->left;
    int value=MID->data;
    _delete(MID->data);// delete E
    delete_node->data=value;// change the delete node's value to E
}
int n,m,x;
int main(){
    scanf("%d",&n);
    // build tree
    while(n--){
        scanf("%d",&x);
        insert(x);
    }
    scanf("%d",&m);
    // delete node
    while(m--){
        scanf("%d",&x);
        _delete(x);
    }
    // travesal the tree
    printf("Infixorder: ");
    inorder(head);
    printf("\n");
    printf("Levelorder: ");
    levelorder(head);
}