#include<stdio.h>
#include<stdlib.h>
int root,n,adjacent_mat[1005][1005];
int dfn[10005],low[10005],k=1;
int ans[10005],idx;
int min(int a,int b){
    return a<b?a:b;
}
//compare function
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
void dfs(int x,int pre){
    // give dfs tree's order
    dfn[x]=low[x]=k++;
    int flag=0;
    int child=0;
    for(int i=1;i<=n;i++){
        if(!adjacent_mat[x][i])continue;//it means not connect
        if(i==pre)continue;// you can't pass through your parent
        if(dfn[i]){
            // if the node has visited -> this edge is backedge
            // compare current node's low and backedge node's dfn
            low[x]=min(low[x],dfn[i]);
        }
        else{
            child++;
            // if not visit, dfs it
            dfs(i,x);
            // renew the current's low compare with children's low
            low[x]=min(low[x],low[i]);
            //  your child can't arrive the node over than you --> articulation point 
            if(dfn[x]<=low[i])flag=1;
         }
    }
    // root has two child -> articulation point
    // node except root && flag==1 -> articulation point
    if((dfn[x]==1&&child>=2)||(flag&&dfn[x]!=1))ans[idx++]=x;
}
int main(){
    scanf("%d %d",&root,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adjacent_mat[i][j]);
        }
    }
    dfs(root,0);
    for(int i=1;i<=n;i++)printf("%d ",dfn[i]-1);
    printf("\n");
    for(int i=1;i<=n;i++)printf("%d ",low[i]-1);
    printf("\n");
    // sort the answer
    qsort(ans,idx,sizeof(ans[0]),cmp);
    for(int i=0;i<idx;i++)printf("%d ",ans[i]);
}