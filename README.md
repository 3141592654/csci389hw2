# CSCI 389 HW2: Hash It Out
Mason Koch and Sebastian Simmons

## Style note

The header files used an indenation of 2 and we used an indentation of 4 for our implementation. 

## Cache Design
We decided to use an unordered_map container for the internal hash table of pointers to the stored values. We also used another unordered_map to keep track of the amount of memory used by each item added to the cache. 

The map hashes keys to a shared_pointer of bytes. The size map maps keys to the size of a given item in the cache. This allows map.clear() to automatically handle the memory requested by the cache since a shared pointer will deallocate memory once no more pointers point to that object.

unordered_map automatically handles collisions and dynamic resizing based on the load factor. 

For set() we created a while loop that will evict until enough memory is free to add a new item. If there is no evictor object given, the cache stops accepting new values until there is enough space to add them.

## FIFO Evictor Design
We decided to use a queue of keys to store which items were first in. 

touch_key(key) only changes the queue when an existing key is used to chance the value in the cache.

evict() pops and returns the oldest item in the queue.

## LRU Evictor Design

We implemented the LRU evictor using a linked list and hash map that maps keys to nodes in the linked list. Touch moves a node to the back of the linked list.


