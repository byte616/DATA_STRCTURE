+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
+                   Data Structure Assignment V                 +
+                              Graph                            +
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +  

Problem 1. Longest River problem

- Description

There are many rivers, each of them connect to main stream's 
confluence. Count every river's length from the bottom to the 
source. Sort them and print their rank by the input order. 

- Solution

How to Backstracking to count the river's length is the most 
important thing in this problem. We can seperate this priblem 
into 3 parts to discuss it.

- Data -

Use a struct to manage all the data this problem give you. The
struct will contain name, length, confluence, and rank. Its 
advantage is when we are sorting, the data can tie together, we 
can use our data conveniently.

- Backstracking -

Before we do the backstracking, the first thing we should do is 
record all confluence's parent and the distance between itself 
and its parent.

Next, we can start from every river's conflence, backstracking
until we arrive the source. In the proccess, we also need to 
accumulate the confluence's length into river's length.

- Sort -

Use qsort to sort the river by their length. Remember when there
are two river has the same length, they share the same rank.
EX:  
       river index    0   1   2
       river length  12  12  50
       river rank     1   1   2
(Therfore, we need to write a loop to give the river rank)

Finally, we need to print out the answer by input order. We can
use simple linear search to match its name and rank from two 
arrary and print the result.

==================================================================

Problem 2. Articulation_point_detection

- Description

Give you an adjacent matrix to represent the vertice's connect
condition. Assign a root, print out the dfs order, low array, and
all the Articulation point (print it by sort). 

- Solution

Implement Tarjan's method, use DFS to got the dfs tree. In the 
recursive process, renew the low's value. According to Articulation
points' definition to find out the Articulation point.

- DFS -

First, give every vertice their dfs order(dfn) and initialize low
as their dfn.

Second, check adjacent vertice by adjacent matrix. If the value is 
'0', we can skip this vertice because it's not connected. When we
encounter the parent nodes we also need to skip it. DFS has direction.
By skip the pre vertice, we can make the undirected graph like a 
directed graph.

Third, check the adjacent vertice is visted or not. It will has 2 cases.

CASE #1:the adjacent vertice has visted
        this means this edge is a backedge, we can renew current 
        vertice's low value by comparing itself and the adjacent
        vertice's dfn. Why not compare with adjacent vertice's 
        low ? It's because it may cause the current vertice pass
        through more than one backedge -> illegal 

CASE #2:the adjacent vertice not visited yet
        it means we can dfs the adjacent vertice and renew our low.
        But which one should be first ? The answer is dfs should 
        before the renew. Because there is a case that current vertice
        go to their child and get a better backedge. that means we
        should get the child's information first. Therefore, we dfs
        firstly, then renew the low. Finally, check the adjacent
        vertice whether it can arrive the vertice over current vertice.
        if not, the current vertice is an Articulation point.

Finally, in the bottom of dfs, we can make the Articulation point
into our ans array. There are two situation will make an Articulation
point.

1. the vertice is root and it has two child

2. the vertice is not the root and his child can't pass over it by
   any backedge

==================================================================

Problem 3. Meeting_points

- Description

There are n people, there will have several edge between people to 
people. Every edge has their cost. We need to find a vertice that 
the total cost everyone come to this position is the cheapest. 

- Solution

We can solve this problem by doing n times Dijkstra. The best method
to implement Dijkstra needs vector and priority queue. However, I didn't
successfully run the priority queue's code. I saw the testcase range 
no more than 20. I think we can just use queue to substitute priority
queue.

- Container -

we should implement queue and vector. Queue we have implement before.
This time we can see how to implement vector:

struct vector{ // definite a new type called vector
    struct edge *data; // vector which can store the struct edge data type
    int size; // record vector's size
    int cap; // record vector's capacity
}v[100005];

There are two basic functions we need:

1.void init(int x):
    if the vector hasn't use yet, malloc one space to it.

2.void push_back(int a,struct edge b):
    push the data into the vector's bottom
    if the vector is fulled, realloc two times vector to it

- Dijkstra -

Before Dijkstra, we store the edge relationship into the adjacent
list(vector).

First, initialize the dis to infinite and psuh the start vertice
and its dis(is 0) into the queue.

Second, use loop to renew our dis until queue has nothing. We can
get the front data first. 

Third, check the adjacent list. If we found we can pass to a vertice
in cheaper way (dis[k.node]>dis[u.node]+k.dis), renew the dis and 
push the vertice and dis into queue. 

Finally, sort the queue and make the smallest cost edge always on the
top. 

After doing n times Dijkstra, choose the total dis cost is the smallest,
print the vertice name and the cost.