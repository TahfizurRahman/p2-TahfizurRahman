#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class LinkedBox{
private:
    int size_;
    int capacity_;
protected:
    Node<T>* head_;
public:
    /**
     * @brief Default constructor
     * @post Sets head_ to nullptr. 
     *       Initializes capacity_ to 64 and size_ to 0. 
     */
    LinkedBox();

    /**
     * @brief Parameterized constructor
     * @param capacity A const reference to an integer to specify the capacity of the LinkedBox
     * @post Sets the head pointer to nullptr. 
     *       Initializes capacity_ to the specified parameter and size_ to 0. 
     * @note If the capacity is 0 or negative, 64 is used instead
     */
    LinkedBox(const int& capacity);

    ~LinkedBox();
    /**
     * @brief Getter for the size_ member
     * @return The integer value stored within the size_ member variable
     */
    int size() const;

    /**
     * @brief Getter for the capacity_ member
     * @return The integer value stored within the capacity_ member variable
     */
    int capacity() const;

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
    bool addItem(const T& target);

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
    bool remove(const std::string& type);

    /**
     * @brief Determines whether the LinkedBox contains an item of the specified type
     * 
     * @param type A const reference to a string denoting 
     *        the type of the item to search for
     * 
     * @return True if items_ contains an object whose getType() 
     *         equals the given parameter. False otherwise.
     */
    bool contains(const std::string& type) const;

    /**
     * @brief Counts the number of distinct intances of the given type stored within the chain
     * 
     * @param type A const reference to a string denoting 
     *        the type of the item to search for
     * 
     * @return An integer representing the number of instances 
     *        of objects whose type is equal to the parameter.
     */
    int count(const std::string& type) const;
};

#include "LinkedBox.cpp"