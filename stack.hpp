#pragma once

#include <iterator>
#include <memory>

namespace stack_t {



template<class T>
class stack_t {
private:
    struct node_t {
        T value;
        std::unique_ptr<T> next;
    };   
    std::unique_ptr<node_t> head;
    void insert(std::unique_ptr<node_t> current, const T& value);
public:
    struct forward_iterator {
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;
        forward_iterator(node_t* ptr) : ptr_(ptr) {};
        T& operator*();
        forward_iterator& operator++();
        forward_iterator operator++(int);
        bool operator==(const forward_iterator* it) const;
        bool operator!=(const forward_iterator& it) const;
        private:
            node_t* ptr_;
            friend stack_t;
    };

    forward_iterator begin();
    forward_iterator end();
    void insert(const forward_iterator& it, const T& value);
    void erase(const forward_iterator& it);
    void pop();
    T top();
    void push(const T& value);
};

}
