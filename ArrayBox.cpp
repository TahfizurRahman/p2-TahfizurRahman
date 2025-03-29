#include "ArrayBox.hpp"

// Default constructor
template <typename T>
ArrayBox<T>::ArrayBox() : capacity_{64}, size_{0}, items_{new T[64]} {}

// Param constructor
template <typename T>
ArrayBox<T>::ArrayBox(const int& capacity) : capacity_{64}, size_{0} {
    if (capacity > 0) { capacity_ = capacity; }

    items_ = new T[capacity_];
}

template <typename T>
int ArrayBox<T>::getIndexOf(const std::string& type, int start, int end) const {
    if (start < 0 || start >= size_) { return -1; }
    if (end < 0 || end > size_) { return -1; }
    
    for (; start < end; start++) {
        if (items_[start].getType() == type) { return start; }
    }

    return -1;
}

template <typename T>
int ArrayBox<T>::count(const std::string& type) const {
    int next_index = getIndexOf(type, 0, size_);
    int count = 0;

    while (next_index != -1) {
        count++;
        next_index = getIndexOf(type, next_index + items_[next_index].size(), size_);
    }

    return count;
}

template <typename T>
bool ArrayBox<T>::contains(const std::string& type) const {
    return getIndexOf(type, 0, size_) != -1;
}

template <typename T>
int ArrayBox<T>::size() const {
    return size_;
}

template <typename T>
int ArrayBox<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool ArrayBox<T>::addItem(const T& target) {
    // Limit capacity
    if (size_ + target.size() > capacity_) { return false; }
    
    // Fill values
    for (int i = 0; i < target.size(); i++) { items_[i + size_] = target; }

    // Increment size
    size_ += target.size();
    
    return true;
}

template <typename T>
bool ArrayBox<T>::remove(const std::string& type) {
    int index = getIndexOf(type, 0, size_);

    // NOT FOUND
    if (index == -1) { return false; }
    
    // Shift elements over
    int spaces = items_[index].size();
    for (; index < size_ - spaces; index++) {
        items_[index] = items_[index + spaces];
    }

    size_ -= spaces;
    
    // Override with null
    for (; spaces > 0; spaces--) {
        items_[index] = T{};
        index++;
    }

    return true;
}

