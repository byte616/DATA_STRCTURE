#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int number[100005],size,tmp;
char string[200005];
// swap function
void swap(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
// read input
void input(){
    fgets(string,200005,stdin);
    for(int i=0;i<strlen(string);i++){
        if(isalnum(string[i]))tmp=tmp*10+string[i]-'0';
        if(string[i]==','){
            number[size++]=tmp;
            tmp=0;
        }
    }
    number[size++]=tmp;
}
// print the procedure of sorting
void print(){
    for(int k=0;k<size;k++){
        if(k)printf(", ");
        printf("%d",number[k]);
    }
    printf("\n");
}
int main(){
    input();// manage input 
    print();
    for(int i=1;i<size;i++){
        int key=number[i],j=i-1;
        while(j>=0&&key<number[j]){// if the previous is bigger
            number[j+1]=number[j]; // make it move to next position
            j--;
        }
        number[j+1]=key;// place the key to correct position
        print();// print the procedure
    }
}