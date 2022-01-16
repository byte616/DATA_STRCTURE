+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
+                   Data Structure Assignment II                +
+                        Stacks and Queues                      +
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +  

Problem 1. Rats in a maze

- Description

In every testcase, we will get a number n, it means the map's size 
is n*n. In the square map, 1 means it can pass, 0 means it can't 
pass. The mouse can only move Down, Right, Up,and Left(must follow
this order to find the path). Start from (0,0) and the destination
is at (n-1,n-1). Find the solution path and print it.
(*must use stack to implement it)

- Solution

This time, we don't use the recursive algorithm to slove this 
problem. We use stack to simulate DFS's proccess. We seperate this 
problem into several parts.

- Stack -

We use array to implement , and we write a struct to declare the 
stack so that it can store two value: row and col. Besides, we need
to implement three basic function: push(), pop(), and empty().

- Search the path -

First, push (0,0) into stack (start position).

Second, use while loop to search until the stack is empty or we find 
the destination.

In the while loop, pop the fist node in the stack and check it arrive 
the destination or not. If so, call print() to backstracking the answer
and break the loop. If not, use for loop to check every directions is 
valid or not. If the node is valid, record the vis array, record the
parent direction, and push the node into stack.

* Direction reprsentation
int dx[4]={0,-1,0,1}; 
int dy[4]={-1,0,1,0}; 
we use dx dy to reprsent the direction and store the reverse order 
because stack is last in first out, the first direction should be put 
at last one so that it can be checked first.

- Backtracking -

when we are searching the path, we record the parent direction. We can 
use it to backtracking the answer path from the destination to the start
position. Finish the backtracking, we can print the answer. 

===================================================================
Problem 2.Infix to Postfix 

- Description

In every testcase, we will get a mathematic expression. We need to check
is it valid or not. If it is invalid, print 0. If it is valid, print 1 and 
its postfix.

- Solution

First, check the expression is valid or not. 

1. ) can't appears before (
2. numbers of ( need equal to numbers of )
3. single digit is not allow
4. number of digits != numbers of operators
5. digit didn't connect

Second, change the infix into postfix

when we encounter ....

1. digits -> print it directly
2. operators -> pop the stack and print until the order of operater greater 
   than the stack top's element
3. ( -> push into stack
4. ) -> pop the stack and print until encounter (
5. when the loop finish, remember to pop out and print all the remaining
   element in stack

===================================================================
Problem 3. Push and pop

- Description

Give you two string, you can adjust the words output method by stack's push
and pop. You need to print all the combination of the legal answer.
i: push
o: pop 
EX: toyz -> tozy
    ->  i o i o i i o o
stack:  t   o   y z
output:   t   o     z y     

- Solution

This problem we can use brute force to find all the probable answer. We 
choose 0 1 subset method to slove it and the concept is below:
choose:
    record the array 
    dfs below
    recover the array
not choose:
    record the array
    dfs below
    recover the array

- Inplement -

Terminal condition:
when the output idx == size-1 (it means we success get a correct answer), 
stop the recurssion and print the answer.

Two recurssive condition:

1. push() : i

when the string's size greater than string's idx, it means we can push the 
word. We set the ans[level] = i, and push the element into stack. Then, we
dfs below. Remember to recover the change.( We should pop the element which 
push in stack, and make string's idx--)

2. pop() : o

when stack has element && new string [idx] == stack's top, it means the word
is same so that we can excute pop(). We set the ans[level] = o, and pop the 
element from the stack, and add one on the output index. Then, we dfs below.
Remember to recover the change.(we should push the element which pop from 
stack, and make the output's idx--)
