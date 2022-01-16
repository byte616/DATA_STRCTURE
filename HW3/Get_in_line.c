#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// linklist's structure
struct node{
    char name[20005];
    struct node *next;
}*head=NULL;
// operation string
char INSERT[]="insert";
char QUERY[]="query";
char SWAP[]="swap";
char DELETE[]="delete";
int t,size=0;
char operation[105];
int idx,_idx;
char name[20005];
void insert(int idx,char *s){
    struct node *POS=head;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->next=NULL;
    strcpy(tmp->name,s);
    // check idx legal or not
    if(size<idx){
        printf("no result\n");
        return;
    }
    while(idx--)POS=POS->next;
    if(POS->next!=NULL)tmp->next=POS->next;
    else tmp->next=NULL; // end remember to point NULL
    POS->next=tmp; 
    size++;
}
void query(int idx){
    struct node *POS=head;
    // check idx legal or not
    if(size<idx||idx<=0){
        printf("no result\n");
        return;
    }
    // move the POS
    while(idx--)POS=POS->next;
    printf("%s\n",POS->name);
}
void _delete(int idx){
    // check idx legal or not
    if(size<idx||idx<=0){
        printf("no result\n");
        return;
    }
    struct node *POS=head,*DELETE_NODE=head->next;
    // record delete node and its previous node
    while(--idx){
        POS=POS->next;
        DELETE_NODE=DELETE_NODE->next;
    }
    if(DELETE_NODE->next!=NULL)POS->next=DELETE_NODE->next;
    else POS->next=NULL;
    free(DELETE_NODE);    
    size--;
}
void swap(int idx1,int idx2){
    // check idx legal or not
    if(idx1>size||idx2>size||idx1<=0||idx2<=0){
        printf("no result\n");
        return;
    }
    struct node *POS1=head;
    while(idx1--)POS1=POS1->next;
    struct node *POS2=head;
    while(idx2--)POS2=POS2->next;
    char tmp[20005];
    // change the data
    strcpy(tmp,POS1->name);
    strcpy(POS1->name,POS2->name);
    strcpy(POS2->name,tmp);
}
int main(){
    // important: make the head node point to the initial store
    struct node *STORE=(struct node*)malloc(sizeof(struct node));
    head=STORE;
    scanf("%d",&t);
    while(t--){
        scanf("%s",operation);
        // check the string and excute the operation
        if(strcmp(operation,INSERT)==0){
            scanf("%d %s",&idx,name);
            insert(idx,name);
        }
        if(strcmp(operation,QUERY)==0){
            scanf("%d",&idx);
            query(idx);
        }
        if(strcmp(operation,DELETE)==0){
            scanf("%d",&idx);
            _delete(idx);
        }
        if(strcmp(operation,SWAP)==0){
            scanf("%d %d",&idx,&_idx);
            swap(idx,_idx);
        }
    }
}