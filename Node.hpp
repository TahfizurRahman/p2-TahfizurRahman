#pragma once

template <typename T>
class Node {
    private:
        T val_; 
        Node* next_;

    public:
        // Delete the default constructor for Node Class
        Node() = delete;

        /**
         * @brief Parameterized Constructor
         * @param val A const reference to the object to store within the Node
         * @param next A pointer to the next Node within the chain. Default nullptr if none provided. 
         */
        Node(const T& val, Node* next = nullptr);
        
        /**
         * @brief Getter for the item stored in val_
         * @return The item stored in val_
         */
        T value() const;

        /**
         * @brief Getter for next_
         * @return The pointer to next Node* in the Chain
         */
        Node<T>* next() const;

        /**
         * @brief Setter for val_
         * @param val A const reference to an Object of type T to set val_ to
         */
        void setValue(const T& val);

        /**
         * @brief Setter for next_
         * @param next A pointer to a Node to be the next Node in the chain
         */
        void setNext(Node* next);
};

#include "Node.cpp"