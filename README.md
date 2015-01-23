# CS-214-Error-Detection
Fall 2014 with Brian Russell


A doubly linked list was used, which helps allocate memory in linear time O(n). Additionally freeing memory in a doubly linked list allows us to have a constant run time of O(1). If a block of memory is released, it may conjoin with any neighboring pieces of memory that are also free. In the code, after a free, one can see if the successor or the predecessor is free memory. If so, the two blocks of memory will combine. For error detection, an array of void * pointers (called memEntry List) was used to keep track of all of the memory allocations as each entry is malloced. Then the array was checked to see if the pointer was ever allocated at a certain memory address. If the address matches with any that was stored in memEntryList, then the free will be a success. The other free error checks were to prevent a free of a variable that was not allocated.

The function sbrk is used to allocate more memory in the heap when all of the available dynamic memory became saturated Conditional statements are also used to reduce fragmentation. If the piece of memory to be allocated was less than a quarter of the entire big_block static array, it would be allocated on the beginning of the heap. Otherwise, if the memory was bigger, then it would be allocated beginning at the midpoint of the big_block static array. Memset is used to initialize everything to 0 in the newly allocated block. For realloc, memcpy and myfree create a new block of memory depending on the new size given and freed the old pointer. I also implemented a check against mallocing a variable with the size of zero and freeing a pointer set to null.
