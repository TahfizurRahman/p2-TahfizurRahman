#pragma once
#include "Node.hpp"

/**
 * @brief Parameterized Constructor
 * @param val A const reference to the object to store within the Node
 * @param next A pointer to the next Node within the chain. Default nullptr if none provided. 
 */
template <typename T>
Node<T>::Node(const T& val, Node* next) : val_{val}, next_{next} {}
        
/**
 * @brief Getter for the item stored in val_
 * @return The item stored in val_
 */
template <typename T>
T Node<T>::value() const {
    return val_;
}

/**
 * @brief Getter for next_
 * @return The pointer to next Node* in the Chain
 */
template <typename T>
Node<T>* Node<T>::next() const {
    return next_;
}

/**
 * @brief Setter for val_
 * @param val A const reference to an Object of type T to set val_ to
 */
template <typename T>
void Node<T>::setValue(const T& val) {
    val_ = val;
}

/**
 * @brief Setter for next_
 * @param next A pointer to a Node to be the next Node in the chain
 */
template <typename T>
void Node<T>::setNext(Node* next) {
    next_ = next;
}