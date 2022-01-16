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
// partition function
int partition(int left,int right){
    int pivot=number[left];// give a pivot
    int i=left,j=right+1;// use the pivot to classify the number
    do{
        do{j--;}while(number[j]>pivot);
        do{i++;}while(number[i]<pivot);
        if(j>i)swap(&number[i],&number[j]);
    }while(j>i);
    swap(&number[left],&number[j]);//place pivot to correct position
    print();// print the sorting procedure
    return j;// return pivot's position 
}
// use recursive deal with left side and right side sorting
void quick_sort(int left,int right){
    if(left<right){
        int mid=partition(left,right);
        quick_sort(left,mid-1);// left side
        quick_sort(mid+1,right);// right side
    }
}
int main(){
    input();// manage input
    quick_sort(0,size-1);// quick sort
}