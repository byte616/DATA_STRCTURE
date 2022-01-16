#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char string[20005];
char new_string[20005];
char stack[200005];
char ans[10005];
int t,size,s_idx;
int idx=-1,*top=&idx;
int _idx=-1,*_top=&_idx;
void push(int *top,char alphabet){
    stack[++*top]=alphabet;
}
char pop(int *top){
    return stack[(*top)--];
}
int empty(int top){
    return top<0;
}
// use brute force search all the combination (0 1 subset)
void dfs(int level){
    // when the output is finish, stop and print the answer 
    if(*_top==size-1){
        for(int i=0;i<level;i++){
            printf("%c ",ans[i]);
        }
        printf("\n");
    }
    else{
        // when the string's size > string's idx, it means we can push the word
        if(s_idx<size){
            ans[level]='i'; // answer set i
            push(top,string[s_idx++]); // stack push the word 
            dfs(level+1); // recursive below
            --s_idx,pop(top); // pop the element push in stack, and make string's idx--
        }
        // when stack has element && new string [idx] == stack's top
        // it means we can pop the word
        if(*top>=0&&*_top<size-1&&new_string[*_top+1]==stack[*top]){
            ans[level]='o'; // answer set o
            ++*_top; // output's idx can move 1
            char c=pop(top); //stack pop the top
            dfs(level+1); //recursive below
            push(top,c),--*_top; //push the element pop from stack, and make the output's idx--

        }
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        s_idx=0;
        idx=-1,_idx=-1;
        scanf("%s",string);
        scanf("%s",new_string);
        size=strlen(string);
        printf("[\n");
        // the length is same and we start searching
        if(strlen(string)==strlen(new_string))dfs(0);
        printf("]\n");
    }
}