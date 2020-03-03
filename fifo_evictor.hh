/*
 * Declare interface for FIFO evictor
 */

#pragma once

#include "evictor.hh"
#include <queue>

//I DON't REMEBER WHAT PUBLIC DOES. https://stackoverflow.com/questions/19079534/how-to-correctly-extend-a-class-in-c-and-writing-its-header-file. UNDERSTAND THIS.
class Fifo_evictor : public Evictor {
  public:
    Fifo_evictor();
    void touch_key(const key_type& key);
    const key_type evict();
 private:
   std::queue<key_type> my_queue_;
     
};

// IMPLEMENT ME
