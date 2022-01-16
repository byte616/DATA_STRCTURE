#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[10005][10005]; // origin map
int vis[10005][10005]; // record visited or not
int par[10005][10005]; //record where it comes from
int path[10005][10005]; // answer map
int t,n;
int dx[4]={0,-1,0,1};// direction 
int dy[4]={-1,0,1,0};
struct edge{ // implement stack  
    int row; 
    int col;
}stack[200005];
// basic function
void push(int *top,struct edge point){
    stack[++*top]=point;
}
struct edge pop(int *top){
    return stack[(*top)--];
}
int empty(int top){
    return top<0;
}
// use backtracking to find the answer map
void print(struct edge node){
    memset(path,0,sizeof(path));
    while(node.row!=1||node.col!=1){
        int i=par[node.row][node.col];
        path[node.row][node.col]=1;
        node.row=node.row-dx[i],node.col=node.col-dy[i];
    }
    path[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",path[i][j]);
        }
        printf("\n");
    }
}
// check the point is legal or not
int is_valid(int x,int y){
    return x>0&&x<=n&&y>0&&y<=n&&map[x][y]=='1'&&!vis[x][y];
}
int main(){
    scanf("%d",&t);
    while(t--){
        // stack's idx
        int idx=-1,*top=&idx;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf(" %c",&map[i][j]);
            }
        }
        struct edge start={1,1};
        par[1][1]=-1;
        push(top,start);
        // use stack to simulate DFS
        while(!empty(idx)){
            struct edge node=pop(top);
            // we arrive the destination
            if(node.row==n&&node.col==n){
                print(node);
                break;
            }
            // use dx dy to find the adjacent position
            for(int i=0;i<4;i++){
                struct edge new_node={node.row+dx[i],node.col+dy[i]};
                // check the position is legal or not
                if(is_valid(new_node.row,new_node.col)){
                    vis[new_node.row][new_node.col]=1;
                    par[new_node.row][new_node.col]=i;
                    push(top,new_node);
                }
            }
        }
    }
}