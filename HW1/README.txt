+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
+                   Data Structure Assignment I                 +
+                       Structs and Arrays                      +
+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +  

Problem 1. Arrays of Structures

- Description

You will get a lot of datas ,including ID, name, vaccine brand,
age, and city. the problem will give you the vaccine brand, and
you need to print the man's information who choose that vaccine.

- Solution

Use struct to store the data, and use a loop to find out who take
target vaccine and print his information.
(use strcmp(string_A,string_B) find the vaccine brand)

==================================================================

Problem 2. ROT13 and KMP

- Description

This problem has many input, I seperate it into several parts.

First, you will get ciphertext. You need to use ROT13 to get a new 
string, and print it.

Second, choose the first five words from the new string to compose 
a key and calculate lps sum. Print the lps sum.

Third, use the key to matching with the input article, print the 
matched words' indexs(should add lps sum on it).

Finally, use the indexes to map the answer_dic. Compose a phrase 
and print it.

- Solution

This problem has several sub-problem, I seperate it into several 
parts to explain.

- ROT13 -

Use 𝐸𝑛(𝑥) = (𝑥 + 𝑛) 𝑚𝑜𝑑 26 to implement the ROT13. The most important
thing is you seperate the alphabet into two cases upper and lower.

- Failure Function-

we have a five words array named key and we need to use it to make a 
failure function. Failure fuction is for recording the longest suffix 
and prefix(can't be the string itself), for example:
-> string: ababc
           prefix         suffix (longest)    failure (use F[5] to record)
a            X               X                F[0]=0
ab           X               X                F[1]=0
aba          a               a                F[2]=1
abab        ab              ab                F[3]=2
ababc        X               X                F[4]=0

First, initialize the F[0] equals to zero, and set two pointers, one 
called i, another called j. In the for-loop, we are going to find F[N].

we compare the string on i and j position, if it failed, we push j to 
the forward and when j=0 or s[i]=s[j] we stop the loop. If s[i]=s[j], 
we can record F[i]=j+1, else the F[i] will become 0.

At the same time, we can record sum of lps because the sum of lpsis the
total of failure function.

- KMP -

Use a while loop to scan all the words in article until it finished. Use 
i and j to be the pointer of article and the key.

If the article[i]!=key[j], we will have two cases. One is j=0, we will 
just let i+1, another is j!=0, we will push j to the last failure position 
and make the changed position compare with the article[i] again.

If article[i]=key[j], we will let i and j plus one. When j=4, it means 
we complete the comparsion, record the index in an array.

- Answer_Dic -

Use fgets to manage the string. I write a struct to make the data 
storing more clear. The struct includes the origin context, the first
alphabet, and the answer context we need.



