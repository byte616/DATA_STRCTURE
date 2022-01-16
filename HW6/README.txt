+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
+                   Data Structure Assignment VI                +
+                        Sorting Algorithms                     +
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +  

Problem 1. Quick Sort

- Description

Sort the number in Quick Sort and print every procedure in the 
sorting. (Constrain: pivot should choose the left side)

- Solution

Use recursive to implement quick sort and use partition function
to choose pivot.  

- Divide and Conquer -

The concept of quick sort's recursive is divide and conquer. How 
we can use divide and conquer manage this problem? First, check 
the range is legal or not. Then, use partition to find the pivot
between left boundary and right boundary.(pivot is correct position)
Finally, recursion in left and right(left~mid-1 && mid+1~right) 
until finish the sort.

- Partition -

We set the the left element as pivot. Every time we scan the array
in the range of left and right. If we find in the condition of i<j
(left pointer < right pointer) && a[i]>pivot && a[j]<pivot: swap 
two element. When i>j, break the loop and swap the pivot and a[j].
(pivot is on correct position)  

EX: 2 5 1 3 4

round #1: pivot = 2

5 & 1 --> should swap (i=1 < j=2 && a[i]=5 > pivot && a[j]=1 <pivot) 
-> result: 1 2 5 3 4 (j finally arrive at index 1,swap with pivot)

round #2: pivot = 1
-> result: 1 2 5 3 4

round #3: pivot = 5
-> result: 1 2 3 4 5

round #4: pivot = 3
-> result: 1 2 3 4 5

round #5: pivot = 4
-> result: 1 2 3 4 5
==================================================================

Problem 2. Selection Sort

- Description

Sort the number in Selection Sort and print every procedure in the 
sorting.

- Solution

Find the smallest element in the unsorted array and swap it to the 
correct position. Continue on this operation until our array is 
aready sorted.

EX: 2 5 1 3 4

round #1:  1
-> result: 1 5 2 3 4 (swap smallest element to unsorted's first place)

round #2:  2
-> result: 1 2 5 3 4

round #3:  3
-> result: 1 2 3 5 4

round #4:  4
-> result: 1 2 3 4 5

==================================================================

Problem 3. Insertion Sort

- Description

Sort the number in Insertion Sort and print every procedure in the 
sorting.

- Solution

Compare with the previous, if the key is smaller than the previous,
move the previous element back. Until there there is no element 
smaller than key, put the key on correct position.Continue on this 
operation until our array is aready sorted.

EX: 2 5 1 3 4

round #1:  
-> result: 2 5 1 3 4

round #2:  
-> result: 2 5 1 3 4

round #3:  
-> result: 1 2 5 3 4 (1 smalller than 2 5, move to their head)

round #4:  
-> result: 1 2 3 5 4

round #5:  
-> result: 1 2 3 4 5
==================================================================

Problem 4. Minimum Gap

- Description

Sort the number in Merge Sort and print every procedure in the 
sorting. Besides, find the minimum gap in the array.

- Solution

Merge the array in the following order: 2, 4, 8, 16, ......
We seperate merge sort in two parts: merge_sort() and merge().

- Merge Sort -

We want to merge the array in order of 2, 4, 8, .... Therefore, 
every loop our merge range is set as 2, 4, 8, ....(s *= 2) and 
we will call merge() to merge the range of array. 

- Merge -

First, seperate the array into two array(we called arr_A and arr_B)
where arr_A and arr_B is well sorted array. Then, we compare two 
array and stored element in order into original array.


- Mnimun Gap -

If our array is well sorted, find the minimum absolute gap in 
the array and print it. 

EX: 2 5 1 3 4

round #1:  
-> result: 2 5 1 3 4 ( (2,5) (1,3) (4) )

round #2:  
-> result: 1 2 3 5 4 ( (1,2,3,5) (4) )

round #3:  
-> result: 1 2 3 4 5 ( (1,2,3,4,5) )