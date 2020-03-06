# CSCI 389 HW2: Hash It Out
Mason Koch and Sebastian Simmons

## Style note

The header files used an indenation of 2 spaces. We used an indentation of 4. 

## Cache Design
We used two unordered maps, one for the hash table of pointers to the stored values and another to track the memory used by each item added to the cache. We used unordered_maps because they handle collisions, dynamic resizing based on a load factor and constant time access for us.

The unordered_map of values hashes keys to a shared_pointer to the value. This allows map.clear() to automatically handle the memory requested by the cache since a shared pointer will deallocate memory once no more pointers point to that object. While it is up the end user to deep copy the resulting value from get(), using a shared_pointer means that if the user keeps the pointer we returned and the pointer is deleted from the cache, the value stays in memory until the user releases that pointer. This is not necessary, but it is certainly more user-friendly.

Another unordered_map hashes the key the size of the stored value. This allows us to keep track of memory as items are added or deleted.

For set(), we check if the user's data is bigger than our cache's maxmem and tell them to jump in a lake if it is. Otherwise, we run a while loop that will evict until enough memory is free to add the new item. If there is no evictor object given, the cache does not accept new values.

## FIFO Evictor Design
We used a queue of keys to store which items were first in. 

touch_key(key) only changes the queue when an existing key is used to chance the value in the cache.

evict() pops and returns the oldest item in the queue.

## LRU Evictor Design

We implemented the LRU evictor using a linked list and hash map that maps keys to nodes in the linked list. This gives us constant time access into the linked list. Touch moves a node to the back of the linked list.
