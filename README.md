# CSCI 389 HW2: Hash It Out
Mason Koch and Sebastian Simmons


## Cache Design
We decided to use a map container for the internal hash table as well as for another hash table that keeps track of the amount of memory used by each item added to the cache. 

The map hashes keys to a shared_pointer of bytes. The size map maps keys to the size of a given item in the cache. This allows map.clear() to automatically handle the memory requested by the cache since a shared pointer will deallocate memory once no more pointers point to that object.

