/*
 * Declare interface for LRU evictor
 */

#pragma once

#include "evictor.hh"
#include <queue>
#include <map>

struct node {
    node* previous;
    node* next;
    key_type payload;
};

//I DON'T REMEBER WHAT PUBLIC DOES. https://stackoverflow.com/questions/19079534/how-to-correctly-extend-a-class-in-c-and-writing-its-header-file. UNDERSTAND THIS.
class Lru_evictor : public Evictor {
  public:
    Lru_evictor();
    ~Lru_evictor();
    void touch_key(const key_type& key);
    const key_type evict();
 private:
   node* head_ = nullptr;
   node* tail_ = nullptr;
   std::map<key_type, node*> pointer_lookup_;
     
};

