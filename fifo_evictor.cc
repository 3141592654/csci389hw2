/*
 * Implementation for FIFO_evictor class
 */

#include "fifo_evictor.hh"


Fifo_evictor::Fifo_evictor() {
    my_queue_ = std::queue<key_type>();
}
void Fifo_evictor::touch_key(const key_type& key) {
    // First quick and dirty approach. Add it to the back of the queue.
    // TODO: REORDER THE QUEUE IF THE KEY IS ALREADY IN IT.
    my_queue_.push(key);
}
const key_type Fifo_evictor::evict() {
    // WE MIGHT BE ABLE TO DO THIS IN FEWER LINES BUT IT IS NOT CLEAR WE CARE
    const key_type retval = my_queue_.front();
    my_queue_.pop();
    return retval;
}




