/*
 * Implementation for Lru_evictor class
 * We do this by having a linked list of the keys. The top of the list is
 * the most recently used (or whatever). We also have a hashmap from the keys
 * to a pointer to the relevant node in the linked list. Then when we set a
 * previously used key, we can rearrange the linked list in constant time.
 *
 * Hmm, do we just implement our own linked list? It would be practice for every programming interview ever.
 */

#include "lru_evictor.hh"
#include <assert.h>


Lru_evictor::Lru_evictor() {
    node* head_ = nullptr;
    node* tail_ = nullptr;
}  // TODO: IS THIS FUNCTION REDUNDANT???

Lru_evictor::~Lru_evictor() {
    node* temp1 = head_;
    node* temp2 = nullptr;
    while (temp1 != nullptr) {
        temp2 = temp1->next;
	delete temp1;
	temp1 = temp2;
    }
}

void Lru_evictor::touch_key(const key_type& key) {
    if (pointer_lookup_.count(key) == 0) {
        // We haven't seen this key before.
        if (head_ == nullptr) {
            // If we have no head, then we must have an empty list. Assert this is true.
            assert(tail_ == nullptr);
            // Initialise our list with a node pointing to nullptr in both directions.
            node* newNode = new node;
            newNode->previous = nullptr;
            newNode->next = nullptr;
            newNode->payload = key_type(key);
            tail_ = newNode;
            head_ = newNode;
            pointer_lookup_[key] = newNode;
        } else {
            // We assert that the list is not empty, so the tail should not be a nullptr
            assert(tail_ != nullptr);
            // It should think the next node is a nullptr, however
            assert(tail_->next == nullptr);
            // Add the new node to the back of the list.
            node* newNode = new node;
            newNode->previous = tail_;
            newNode->next = nullptr;
            newNode->payload = std::string(key);
            tail_->next = newNode;
            tail_ = newNode;
            pointer_lookup_[key] = newNode;
        }
    } else {
        // The key is in our index map
        node* ref = pointer_lookup_[key];
        // Add in a bunch of runtime assertions
        assert(ref != nullptr);              // We should never point to a nullptr
        assert(head_ != nullptr);             // Our list should exist
        assert(head_->previous == nullptr);   // There shouldn't be anything older than the oldest element
        assert(tail_ != nullptr);             // Again, our list should exist
        assert(tail_->next == nullptr);       // There shouldn't be anything younger than our youngest element
        if (head_ != tail_) {
            assert(head_->next != nullptr);
            assert(tail_->previous != nullptr);
        }
        // Right, our list looks vaguely sane.
        if (ref == tail_) {
            // The key is already at the back of our list, we don't need to do anything.
            return;
        }
        if (ref == head_) {
            head_ = head_->next;
            head_->previous = nullptr;
            tail_->next = ref;
            ref->previous = tail_;
            tail_ = ref;
            tail_->next = nullptr;
            return;
        }
        ref->previous->next = ref->next;
        ref->next->previous = ref->previous;
        tail_->next = ref;
        ref->previous = tail_;
        ref->next = nullptr;
        tail_ = ref;
	tail_->next = nullptr;
    }
}
const key_type Lru_evictor::evict() {
    if (head_ == nullptr) {
        assert(tail_ == nullptr);
        return nullptr;
    }
    assert(tail_ != nullptr);
    key_type retval = head_->payload;
    node* temp = head_->next;
    delete head_;
    head_ = temp;
    if (head_ != nullptr) {
        head_->previous = nullptr;
    } else {
        tail_ = nullptr;
    }
    pointer_lookup_.erase(retval);
    return retval;
}


