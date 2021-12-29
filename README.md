# Project 1a : Boggle Solver (in C)

## How to compile

To compile `spellcheck`

```
make spellcheck
```

To compile `onePlayerBoggle`

```
make onePlayerBoggle
```

## Testing using ./test.sh

Note the test file may take some time to run because of `valgrind`. If you are completing this project on replit, this may be quite, quite slow. I recommend you use smaller dictionaries and test different aspects of your program and avoid simply testing with `./teset.sh`

## Help Received

Please document any help you received in completing this lab. Note that the what you submit should be your own work. Refer to the syllabus for more details. 

Kate Halushka and I had a conceptual talk about how to approach the recursive boggle function fairly early on, but otherwise I did not recieve any help :)

## Describe your work

llist.c Process:

for ll_init() I  allocated space in memory for a llist_t structure then I made the head of the list NULL and the size zero and returned that list.

for ll_delete() starting at the head I loop through the list freeing the value of each node and then the node itself until the list is empty and I free the linked list pointer.

for ll_push() I allocated space in memory for a new node. Then I set the value of the node to be the string passed in. Lastly I point the new nodes next to the current head and the head pointer to the newest node.

hashmap.c Process;

for hm_init() I  allocated space in memory for a hashmap_t structure. Next a set the number of  buckets to the initial bucket value. Then I allocate space in memory for a array of size num buckets that holds llist_t pointers and set the hm buckets to point at it. Lastly I fill each index of the bucket array with an empty llist_t, set the size to zero and return the hm.

for _resize() I  allocated space in memory for another hashma_t structure. Next a set the number of  buckets to the initial bucket value multiplied by 2. Then I allocate space in memory for a array of size new num buckets that holds llist_t pointers and set the hm buckets to point at it. Then I fill each index of the new bucket array with an empty llist_t. I then go through the orginal hasmap and transfer each node over tho the new hasmap. Following that I make the orginal hm point to the new hashmaps buckets array and free the newer hashmap.

for hm_delete() I loop through the hasmap buckets array and ue ll_delete() nto delete the list at each index. Then I free the buckets array itself, and lastly I free the hasmap.

for hm_check() I find the hasvalue of the desired value. Then starting at the head of the list at the has value i chceck to see if the value of the node matches the desired value using string compare. If the value is found in the list the function returns true, otherwise it returns false.

boogle.c Proccess:
for bg_init() I first make sure to creat a dictionary hm by taking in a txt file and adding each of the words to a hm. then I make sure that bg-> dict is set to point to that hm.

for bg_all_words() I create a llist_t pointer then I loop through the hm of all of the words found in the boggle board and add them as a node in the llist. after tht I return the llist of all of the found words.

for _bg_all_words() I start by checking all of the base bases. If any of the base cases are met the program returns. If they don't then the letter at the passed index is added to the word and the index is markd as visited. The the program recurses to each of the other possible directions the next letter in the board could me at.

