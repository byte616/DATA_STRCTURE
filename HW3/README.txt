+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
+                   Data Structure Assignment III               +
+                            Linked list                        +
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +  

Problem 1. Get in line

- Description

It's a basic linked list implement problem. With the initial node
index 0, all the customers line in 1~n. We need to implement insert
, delete, swap, and query. According to every operation, we need
to check is legal or not. If so, excute the operation. If not, print
"no result".

- Solution

Implement Linked list. It has four function need to implement.

- Insert -

We should insert a element after the index. First, check the index
valid or not. If so, move the POS from the head to the index and 
connect the element into list.

- Delete -

Delete the index's element. Check the valid position or not at first.
Next, move the DELETEPOS to the index. Remember to record the previous
position so that we can connect the DELETEPOS's next position.

- Swap -

Check the position valid or not. If so, swap two position's data.

- Query -

Check the position valid or not. If so, print the name.

- Notice -

1. Remember to make the head node point to the initial position.
2. We can use variable size to help check the validity.

==================================================================

Problem 2. Elimination game

- Description

It's s classical problem called Josephus Problem. We should kill 
people in the specified order. People who is killed should be 
deleted from linked list. We need to kill people until there is 
only one survivor. Be careful that the direction has clockwise 
and counter clockwise.

- Solution

Implement Circular double linked list.

- String proccessing -

Use fgets to get the input and use strtok to split the string by 
", ". Remember to make the last string's last word = '\0', otherwise
it will be '\n'. When you print it, you will got a presentation 
error.

- Build Linked List -

Implement the linked list in the input order. Remember to link the 
previous and the next. It will be more convenient to search in any 
direction. Finally, we should make the head connect to the end, a 
circular linked list is finished. 

- Kill and Delete -

Delete the node by k steps until we left only one node. We should print
the name before delete. Remember to record the next position of the
delete position because it will be the next start position. We have two
case(direction), if we encounter clockwise, we use next to delete position.
If we encounter counter-clockwise, we use prev to delete position. That's
why I choose double linked list to solve this problem.