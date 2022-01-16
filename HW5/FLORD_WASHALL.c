#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,m,dis[105][105],test_case=1;
char name[105][105];
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    while(scanf("%d%d",&n,&m)&&(n||m)){
        int mi=1e9;
        char mi_name[105];
        for(int i=1;i<=n;i++){
            scanf("%s",name[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)dis[i][j]=0;
                else dis[i][j]=1e9;
            }
        }
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=n;j++){
                sum+=dis[i][j];
            }
            if(sum<mi){
                mi=sum;
                strcpy(mi_name,name[i]);
            }
        }
        printf("Case #%d %s\n",test_case++,mi_name);
    }
}
