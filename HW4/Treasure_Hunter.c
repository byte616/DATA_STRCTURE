#include<stdio.h>
#include<stdlib.h>
// tree's data
struct node{
    int data;
    struct node *left,*right;
}*head=NULL;
int n,m,x,key,treasure;
// road is use to record root -> key and root -> treasure's path
int road_key[305],road_treasure[305],idx1,idx2;
// search is designed to help insert function
struct node* search(struct node *POS,int x){
    struct node *tmp=POS;
    if(!tmp)return NULL;
    if(x>tmp->data){
        if(tmp->right){
            return search(tmp->right,x);
        }
        else return tmp;// return previous node to insert node after
    }
    else{
        if(tmp->left){
            return search(tmp->left,x);
        }
        else return tmp;
    }
}
// find the path from root to destination
void path(int destination,int road[],int *idx){
    struct node* tmp=head;
    while(tmp){
        road[(*idx)++]=tmp->data;
        if(tmp->data==destination)return;
        if(tmp->data>destination)tmp=tmp->left;
        else tmp=tmp->right;
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
int min(int a,int b){
    if(a<b)return a;
    return b;
}
int main(){
    scanf("%d",&n);
    // build tree
    while(n--){
        scanf("%d",&x);
        insert(x);
    }
    scanf("%d %d",&key,&treasure);
    // record the path from root to destination 
    path(key,road_key,&idx1);
    path(treasure,road_treasure,&idx2);
    int twist=0;// twist is use to record the last element both road are the same
    for(int i=0;i<min(idx1,idx2);i++){
        if(road_key[i]!=road_treasure[i]){
            break;
        }
        twist=i;
    }
    // print the path
    for(int i=0;i<idx1;i++){// print root -> key
        if(i)printf("->");
        printf("%d",road_key[i]);
    }
    for(int i=idx1-2;i>=twist;i--){// print key ->twist
        printf("->");
        printf("%d",road_key[i]);
    }
    for(int i=twist+1;i<idx2;i++){// print twist ->treasure
        printf("->");
        printf("%d",road_treasure[i]);
    }
}