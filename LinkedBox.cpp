#include "LinkedBox.hpp"


/**
 * @brief Default constructor
 * @post Sets head_ to nullptr. 
 *       Initializes capacity_ to 64 and size_ to 0. 
 */
template <typename T>
LinkedBox<T>::LinkedBox():head_{nullptr}, size_{0}, capacity_{64}{}
/**
 * @brief Parameterized constructor
 * @param capacity A const reference to an integer to specify the capacity of the LinkedBox
 * @post Sets the head pointer to nullptr. 
 *       Initializes capacity_ to the specified parameter and size_ to 0. 
 * @note If the capacity is 0 or negative, 64 is used instead
 */
template <typename T>
LinkedBox<T>::LinkedBox(const int& capacity):head_{nullptr}, size_{0}, capacity_{64}{
    if (capacity > 0) {
         capacity_ = capacity; 
        }
}

/**
 * @brief Getter for the size_ member
 * @return The integer value stored within the size_ member variable
 */
template <typename T>
int LinkedBox<T>::size()const { 
    return size_; 
}

/**
 * @brief Getter for the capacity_ member
 * @return The integer value stored within the capacity_ member variable
 */
template <typename T>
int LinkedBox<T>::capacity()const{ 
    return capacity_;
}

/**
 * @brief Appends the target item to the chain such that
 *      1) The current size_ and target.getSize() is small enough 
 *         that the item can be added without exceeding the LinkedBox capacity_
 *      2) A new Node whose value equals the target item is created 
 *         and inserted at the head (ie. at the front of the chain)
 * 
 * @param target A const reference to the item (of the templated type) to be added
 * 
 * @return True if the add was successful. False otherwise.
 * @post Increment size_ (if the item was added) by the size of the added object.
 * 
 * @example Given the following instructions, and a capacity 8 LinkedBox:
            addItem(Pawn)   // Pawn size = 1
            addItem(Rook)   // Rook size = 2
            addItem(Queen)  // Queen size = 3
            addItem(Pawn)   // Pawn size = 1
            addItem(Rook)   // Rook size = 2

            Our LinkedBox Chain will look like: 
            "PAWN(head)->QUEEN->ROOK->PAWN" (size = 7) after all insertions.

            Notice, since Rook is of size 2, the add fails, 
            as adding it would make our size exceed capacity 8.
    */
template <typename T>
bool LinkedBox<T>::addItem(const T& target){
    if (size_ + target.size() > capacity_) { 
        return false;
    }
    Node<T>* newNode = new Node<T>(target, nullptr);
    if (head_ == nullptr) {
        head_ = newNode;
    } 
    else {
        Node<T>* current = head_;
        while (current->next() != nullptr) {
            current = current->next();
        }
        current->setNext(newNode);
    }
    size_ += target.size();
    return true;
}

/**
 * @brief Removes the first Node in the chain whose value() 
 *      is an object with getType() [ie. the type] equals the stringified type specified
 * 
 *      If no object of the given type is found, the remove fails.
 *  
 * @param type A const reference to a string specifying the type of the object to remove
 * @post 1) The Node storing the object of the target type is de-allocated.
 *       2) The head_ (or next_ pointer) of the Node preceding the deleted Node is updated 
 *      
 * @return True if the remove operation was successfully performed. False otherwise.
 * @example Given a chain of the form: "PAWN(head)->ROOK->PAWN"
 *      If we remove an object whose type is a PAWN, we'll have "ROOK(head)->PAWN"
 *      Notice, we removed the *leftmost* instance.
 */
template <typename T>
bool LinkedBox<T>::remove(const std::string& type) {
    Node<T>* current = head_;
    Node<T>* prev = nullptr;
    while (current != nullptr){
        if (current->value().getType() == type){
            if (prev == nullptr) {
                head_ = current->next();
            } 
            else{
                prev->setNext(current->next());
            }
            size_ -= current->value().size();
            delete current;
            return true;
        }
        prev = current;
        current = current->next();
    }
    return false;
}

/**
 * @brief Determines whether the LinkedBox contains an item of the specified type
 * 
 * @param type A const reference to a string denoting 
 *        the type of the item to search for
 * 
 * @return True if items_ contains an object whose getType() 
 *         equals the given parameter. False otherwise.
 */
template <typename T>
bool LinkedBox<T>::contains(const std::string& type) const{
    Node<T>* current = head_;
    while (current != nullptr){
        if (current->value().getType() == type){
            return true;
        }
        current = current->next();
    }
    return false;
}
/**
 * @brief Counts the number of distinct intances of the given type stored within the chain
 * 
 * @param type A const reference to a string denoting 
 *        the type of the item to search for
 * 
 * @return An integer representing the number of instances 
 *        of objects whose type is equal to the parameter.
 */
template <typename T>
int LinkedBox<T>::count(const std::string& type) const{
    int count = 0;
    Node<T>* current = head_;
    while (current != nullptr){
        if (current->value().getType() == type){
            count++;
        }
        current = current->next();
    }
    return count;
}
