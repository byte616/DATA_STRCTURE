#include<stdio.h>
#include<string.h>
// use struct store the data
struct info{
    char id[15];
    char name[30];
    char vaccine_brand[35];
    int age;
    char city[25];
}people[25];
int main(){
    int n;
    char target[35];
    scanf("%d",&n);
    //input the data
    for(int i=0;i<n;i++){
        scanf("%s%s%s%d%s",people[i].id,people[i].name,people[i].vaccine_brand,&people[i].age,people[i].city);
    }
    scanf("%s",target);
    //find out the person who choose target vaccine, print his information
    for(int i=0;i<n;i++){
        if(strcmp(target,people[i].vaccine_brand)==0){
            printf("%s %s %s %d %s\n",people[i].id,people[i].name,people[i].vaccine_brand,people[i].age,people[i].city);
        }
    }
}