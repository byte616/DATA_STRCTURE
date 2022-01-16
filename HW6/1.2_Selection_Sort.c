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
    // selection sort
    for(int i=0;i<size-1;i++){
        int min_idx=i;
        for(int j=i+1;j<size;j++){// find the smallest element
            if(number[j]<number[min_idx])min_idx=j;
        }
        swap(&number[min_idx],&number[i]);// swap the smallest element to the correct position
        print();// print the procedure
    }
}