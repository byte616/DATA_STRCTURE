#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,dis[105],test_case=1;
char name[105][105];
/*******VECTOR*******/
// vector's data
struct edge{
    int node;
    int dis;
};
struct vector{
    struct edge *data;
    int size;
    int cap;
}v[100005];
// vector's function
void init(int x){
    v[x].data=(struct edge*)malloc(sizeof(*v[x].data));
    v[x].cap=1;
}
void push_back(int a,struct edge b){
    if(v[a].size+1>=v[a].cap)v[a].data=(struct edge*)realloc(v[a].data,v[a].cap*2*sizeof(*v[a].data)),v[a].cap*=2;
    v[a].data[v[a].size++]=b;
}
/********END********/
/*******QUEUE*******/
// queue's data
struct queue{
    int dis;
    int node;
}q[1000005];
int top=-1,rear=-1;
// queue's function
int empty(){
    return rear==top;
}
void push(struct queue x){
    q[++rear]=x;
}
struct queue pop(){
    return q[++top];
}
int cmp(const void* a,const void* b){
    return (*(struct queue*)b).dis-(*(struct queue*)a).dis;
}
/********END********/
int main(){
    // input until (0,0)
    while(scanf("%d%d",&n,&m)&&(n||m)){
        int mi=1e9;
        char mi_name[105];
        for(int i=1;i<=n;i++){
            scanf("%s",name[i]);
        }
        while(m--){
            int from,to,weight;
            scanf("%d%d%d",&from,&to,&weight);
            // if vector has nothing, initialize the vector
            if(!v[from].size)init(from);
            if(!v[to].size)init(to);
            struct edge p;
            p.dis=weight,p.node=to;
            push_back(from,p);
            p.node=from;
            push_back(to,p);
        }
        // implement n times Dijkstra tofind the cheapest way
        for(int i=1;i<=n;i++){
            // intialize distance to infinte
            memset(dis,0x3f,sizeof(dis));
            struct queue p;
            p.node=i,p.dis=0;
            dis[i]=0;
            push(p);
            // Dijkstra
            while(!empty()){
                struct queue u=pop();
                if(u.dis>dis[u.node])continue;
                // check the adjacent list
                for(int j=0;j<v[u.node].size;j++){
                    struct edge k=v[u.node].data[j];
                    // if we have better dis, renew it
                    if(dis[k.node]>dis[u.node]+k.dis){
                        dis[k.node]=dis[u.node]+k.dis;
                        struct queue p;
                        p.node=k.node,p.dis=dis[k.node];
                        push(p);
                        // make the cheapest path upper 
                        qsort(q+top,rear-top,sizeof(q[0]),cmp);
                    }
                }
            }
            int sum=0;
            // calculate the final cost
            for(int j=1;j<=n;j++)sum+=dis[j];
            // choose best answer
            if(sum<mi){
                mi=sum;
                strcpy(mi_name,name[i]);
            }
        }
        printf("Case #%d %s\n",test_case++,mi_name);
    }
}