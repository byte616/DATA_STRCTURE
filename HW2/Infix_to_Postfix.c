#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char expression[20005];
char stack[20005];
char c;
int le=0,ri=0,digits=0,flag=0,size;
// check the expression is valid or not
int check(char *expression){
    if(size<2)return 0;// single digit is not allow
    for(int i=0;i<size;i++){
        if(*expression=='(')le++;
        else if(*expression==')')ri++;
        else if(isdigit(*expression))digits++,flag++;
        else digits--,flag=0;
        if(ri>le)return 0;// ) can't appear before (
        if(flag>1)return 0;// digit can't connect
        expression++;
    }
    if(ri!=le)return 0;// ( != )
    if(!digits)return 0;// operator = digit is not allow
    return 1;
}
// * / > +- > others
int order(char x){
    if(x=='/'||x=='*')return 2;
    else if(x=='+'||x=='-')return 1;
    return 0;
}
// basic function
void push(int *top,char alphabet){
    stack[++*top]=alphabet;
}
char pop(int *top){
    return stack[(*top)--];
}
int empty(int top){
    return top<0;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int idx=-1,*top=&idx;
        scanf("%s",expression);
        le=0,ri=0,digits=0,flag=0,size=strlen(expression);
        if(check(expression)){// check valid or not  
            printf("1 ");
            for(int i=0;i<size;i++){
                // digit print directly
                if(isdigit(expression[i]))printf("%c",expression[i]);
                else if(expression[i]=='('){
                    push(top,'(');
                }
                else if(expression[i]==')'){
                    // pop the stack until encounter ( 
                    while((c=pop(top))!='('){
                        printf("%c",c);
                    }
                }
                else{
                    // pop the stack until the order of operater greater than the stack top 
                    while(order(stack[*top])>=order(expression[i])){
                        c=pop(top);
                        printf("%c",c);
                    }
                    push(top,expression[i]);
                }
            }
            // take out the remain operators
            while(*top>=0){
                c=pop(top);
                printf("%c",c);
            }
            printf("\n");
        }
        else printf("0\n");
    }
}