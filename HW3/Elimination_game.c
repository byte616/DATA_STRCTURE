#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// linked list structure (double linked list)
struct node{
    char name[105];
    struct node *next;
    struct node *prev;
}*head=NULL;
int num,k,d;
char name[10005][105],string[10005];
// build the circular double linked list
void build(){
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    strcpy(tmp->name,name[0]);
    head=tmp;
    struct node *POS=head;
    for(int i=1;i<num;i++){
        struct node *tmp=(struct node*)malloc(sizeof(struct node));
        strcpy(tmp->name,name[i]);
        POS->next=tmp;
        tmp->prev=POS;
        // the last data should link the head
        if(i==num-1){
            tmp->next=head;
            head->prev=tmp;
        }
        else POS=POS->next;
    }
}
// clockwise: next to kill
void clockwise(){
    struct node *POS=head,*tmp=NULL;
    while(--num){
        int x=k;
        while(x--)POS=POS->next;// move
        printf("%s is killed.\n",POS->name);
        POS->prev->next=POS->next;// delete the node
        POS->next->prev=POS->prev;
        tmp=POS->next;
        free(POS);
        POS=tmp;// POS remeber to point to tmp after free
    }
    printf("%s is survived.\n",POS->name);
}
// counter clockwise: prev to kill
void counter(){
    struct node *POS=head,*tmp=NULL;
    while(--num){
        int x=k;
        while(x--)POS=POS->prev;// move
        printf("%s is killed.\n",POS->name);
        POS->prev->next=POS->next;// delete the node
        POS->next->prev=POS->prev;
        tmp=POS->prev;
        free(POS);
        POS=tmp;// POS remeber to point to tmp after free
    }
    printf("%s is survived.\n",POS->name);
}
int main(){
    // manage input string 
    char s[3]=", ";
    char *token=strtok(string,s); // use strtok to split the string by ", "
    while(token!=NULL){
        strcpy(name[num++],token);
        token=strtok(NULL,s);
    }fgets(string,10000,stdin);
    
    // the last word has '\n', we need to make it be '\0' by hand
    name[num-1][strlen(name[num-1])-1]='\0';
    build();
    scanf("%d%d",&k,&d);
    if(d==1)clockwise();
    else counter();    
}
