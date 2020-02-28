/*
 * Implementation for Cache class and various other things
 */

#include <functional>
#include <memory>
#include "cache.hh"
#include "evictor.hh"  //https://stackoverflow.com/questions/5319906/error-expected-class-name-before-token


class Cache::Impl {
  public:
    Impl(Cache::size_type maxmem,
        float max_load_factor = 0.75, 
        Evictor* evictor = nullptr,
        Cache::hash_func hasher = std::hash<key_type>()): maxmem_(maxmem), max_load_factor_(max_load_factor), evictor_(evictor), hasher_(hasher) {
        // Do nothign yet 
    }
    ~Impl() {
        // Do nothing
    }

    void set(key_type key, Cache::val_type val, Cache::size_type size){
        // Do nothing
    }
    Cache::val_type get(key_type key, Cache::size_type& val_size) const {
        const char* retval = new char[5];
        return retval;
    }
    bool del(key_type key) {
        return true;
    }
    Cache::size_type space_used() const {
        return 42;
    }
    void reset() {
        // Do nothing
    }
  private:
    Cache::size_type maxmem_;
    float max_load_factor_;
    Evictor* evictor_;
    Cache::hash_func hasher_;


};


// Ape the given Fridge example
Cache::Cache(size_type maxmem, float max_load_factor, Evictor* evictor, Cache::hash_func hasher) : pImpl_(new Impl(maxmem, max_load_factor, evictor, hasher)) {
    //return new Impl;//(maxmem, max_load_factor, evictor, hasher);

}

Cache::~Cache() {
    //~Impl;  //Eh just try to get this to compile.
    //delete pImpl_;
}

// Hmm. Maybe we don't actually want to pass it the arguments:
void Cache::set(key_type key, val_type val, Cache::size_type size){
    pImpl_->set(key, val, size);
}

Cache::val_type Cache::get(key_type key, Cache::size_type& val_size) const {
    return pImpl_->get(key, val_size);
}

bool Cache::del(key_type key) {
    return pImpl_->del(key);
}

Cache::size_type Cache::space_used() const {
    return pImpl_->space_used();
}


void Cache::reset() {
    pImpl_->reset();
}

