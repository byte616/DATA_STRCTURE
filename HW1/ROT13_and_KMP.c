#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct ans_dic{
    char string[205];
    char alphabet;
    char context[205];
}answer[55];
char ciphertext[2000005],article[2000005];
char key[10];
int failure[10],sum_of_lps=0,indexes[15],idx=0;
void KMP(char article[],char key[]){
    // use failure function find the string fastly
    int i=0,j=0,size=strlen(article);
    while(i<size){
        if(article[i]!=key[j]){
            if(!j)i++;
            else j=failure[j-1];
        }
        else i++,j++;
        if(j==4)indexes[idx++]=i-5+sum_of_lps+1,j=failure[j-1];
    }
}
void Failure(char s[]){ 
    // record the longest suffix and prefix
    int j=0;
    failure[0]=0;
    for(int i=1;i<5;i++){
        j=failure[i-1];
        while(j!=0&&s[i]!=s[j])j=failure[j-1];
        if(s[j]==s[i])failure[i]=j+1;
        else failure[i]=0;
        sum_of_lps+=failure[i];
    }
}
char rot_13(char c){
    // use 𝐸𝑛(𝑥) = (𝑥 + 𝑛) 𝑚𝑜𝑑 26 implement rot 13
    if(isupper(c)){
        int x=c-'A';
        x=(x+13)%26;
        return 'A'+x;
    }
    else{
        int x=c-'a';
        x=(x+13)%26;
        return 'a'+x;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    // manage rot_13 problem
    scanf("%s",ciphertext);
    int size=strlen(ciphertext);
    for(int i=0;i<size;i++){
        ciphertext[i]=rot_13(ciphertext[i]);
    }
    printf("%s\n",ciphertext);
    // choose the first five elements to generate a key
    for(int i=0;i<5;i++){
        printf("%c",ciphertext[i]);
        key[i]=ciphertext[i];
    }
    printf("\n");
    // build failure function
    Failure(key);
    printf("%d\n",sum_of_lps);
    // manage KMP problem
    getchar();
    fgets(article,2000000,stdin);
    KMP(article,key);
    for(int i=0;i<idx;i++){
        printf("%d\n",indexes[i]);
    }
    // read the answer_dic
    for(int i=0;i<52;i++){
        fgets(answer[i].string,200000,stdin);
        answer[i].alphabet=answer[i].string[0];
        int size=strlen(answer[i].string),k=0;
        for(int j=2;j<size;j++){
            answer[i].context[k++]=answer[i].string[j];
        }
        answer[i].context[k-1]='\0';
        //printf("%s\n",answer[i].context);
    }
    // find the secret message
    for(int i=0;i<idx;i++){
        for(int j=0;j<52;j++){
            int x=answer[j].alphabet;
            if(x==indexes[i]){
                printf("%s ",answer[j].context);
                break;
            }
        }
    }
}