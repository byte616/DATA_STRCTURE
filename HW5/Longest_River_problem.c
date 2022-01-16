#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,o;
int par[500005],par_dis[500005];
// river's data
struct rank{
    char name[105];
    int length;
    int confluence;
    int RANK;
}river[500005];
char order[500005][105];
//compare function
int cmp(const void *a,const void *b){
    return (*(struct rank*)b).length-(*(struct rank*)a).length;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s %d %d",river[i].name,&river[i].confluence,&river[i].length);
    }
    scanf("%d",&o);
    while(o--){
        int pa,child,dis;
        scanf("%d %d %d",&pa,&child,&dis);
        //construct confluence's parent relationship and its distance
        par[child]=pa;
        par_dis[child]=dis;
    }
    // backstracking the river's length
    for(int i=1;i<=n;i++){
        // record the origin river order
        strcpy(order[i],river[i].name);
        // use loop to calculate every river's length
        while(river[i].confluence!=0){
           int x=river[i].confluence;
           river[i].length+=par_dis[x];
           river[i].confluence=par[x];
       }
    }
    // sort and assign the rank
    qsort(river+1,n,sizeof(river[1]),cmp);
    int Rank=0;
    for(int i=1;i<=n;i++){
        if(river[i].length==river[i-1].length)river[i].RANK=Rank;
        else river[i].RANK=++Rank;
    }
    // use linear search to find the correct rank and print it
    for(int i=1;i<=n;i++){
        printf("%s ",order[i]);
        for(int j=1;j<=n;j++){
            if(!strcmp(river[j].name,order[i])){
                printf("%d\n",river[j].RANK);
                break;
            }
        }
    }
}