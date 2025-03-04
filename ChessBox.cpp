// File: ChessBox.cpp
// Author: Tahfizur Rahman 
// Date: 03/04/2025
// A Source files that defines ChessBox

#include "ChessBox.hpp"

/**
 * Default constructor
 * @post 
 *  1) Default initializes P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
 *  2) Initializes ArrayBox members with capacity 64
 */
ChessBox::ChessBox():P1_COLOR_{"BLACK"}, P2_COLOR_{"WHITE"}, P1_BOX_{64}, P2_BOX_{64} {}

/**
 * Parameterized Constructor
 * @param color1 A const reference to the color of the ChessPiece (a string)
 * @param color2 A const reference to the color of the ChessPiece (a string)
 * 
 * @param capacity An integer describing the capacity of each player's ArrayBox, 
 *                 with default capacity 64.
 * 
 * @note If either color1 or color2 contains non-alphabetic characters, 
 *          set P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
 *       
 *       If both strings are thus purely alphabetic, 
 *          they are transformed and stored in uppercase.
 *       Now, if the provided colors are equal, set color1 to "BLACK" and color2 to "WHITE"
 *
 *       If the specified capacity is not positive (ie. <= 0) or not provided, 
 *          64 is used instead.
 * 
 * Also note, there are NO default values for color1 or color2 (ie. we must specify them).
 * 
 * @post Initializes ArrayBox members with the specified capacity. 
 *       All strings are initialized as described above. 
 */
ChessBox::ChessBox(const std::string& color1, const std::string& color2, int capacity) : P1_BOX_{capacity}, P2_BOX_{capacity} {
    std::string color1Upper = "";
    std::string color2Upper = "";

    for (size_t i = 0; i < color1.size(); i++) {
        char c = color1[i];
        if (c >= 'a' && c <= 'z') {
            color1Upper += c - 'a' + 'A';
        } 
        else {
            color1Upper += c;
        }
    }
    for (size_t i = 0; i < color2.size(); ++i) {
        char c = color2[i];
        if (c >= 'a' && c <= 'z') {
            color2Upper += c - 'a' + 'A';
        } 
        else {
            color2Upper += c;
        }
    }

    if (color1Upper != color1 || color2Upper != color2 || color1Upper == color2Upper) {
        P1_COLOR_ = "BLACK";
        P2_COLOR_ = "WHITE";
    } else {
        P1_COLOR_ = color1Upper;
        P2_COLOR_ = color2Upper;
    }
}
/**
 * @brief Getter for P1_Color
 * @return The string value stored in P1_COLOR
 */
std::string ChessBox::getP1Color() const{
    return P1_COLOR_;
}

/**
 * @brief Getter for P2_Color
 * @return The string value stored in P2_COLOR
 */
std::string ChessBox::getP2Color() const{
    return P2_COLOR_;
}

/**
 * @brief Getter for P1_BOX
 * @return The ArrayBox<ChessPiece> (ie. the value) of P1_BOX_
 */
ArrayBox<ChessPiece> ChessBox::getP1Pieces() const{
    return P1_BOX_;
}

/**
 * @brief Getter for P2_BOX
 * @return The ArrayBox<ChessPiece> (ie. the value) of P2_BOX_
 */
ArrayBox<ChessPiece> ChessBox::getP2Pieces() const{
    return P2_BOX_;
}

/**
 * @brief Adds a given ChessPiece object to the ArrayBox corresponding to its color:
 *      - If the color of the given piece matches P1_COLOR_, add it to P1_BOX_
 *      - If the color of the given piece matches P2_COLOR_, add it to P2_BOX_
 *      - If the color does not match either box, or the corresponding box doesn't have
 *           enough remaining space to add the piece, the add operation fails.
 * 
 * @param piece A const reference to a ChessPiece object 
 *              that is to be added to one of the ArrayBoxes
 * 
 * @return True if the piece was added successfully. False otherwise.
 *
 */
bool ChessBox::addPiece(const ChessPiece& piece) {
    if (piece.getColor() == P1_COLOR_) {
        return P1_BOX_.addItem(piece);
    }
    else if (piece.getColor() == P2_COLOR_) {
        return P2_BOX_.addItem(piece);
    }
    return false;
}

/**
 * @brief Removes a ChessPiece of the given type 
 *        if one exists in the ArrayBox corresponding to the given color
 * 
 * @param type A const reference to an uppercase string 
 *             representing the type of the ChessPiece to remove
 * @param color A const referene to an uppercase string 
 *             representing the color of the ChessPiece to remove
 * 
 * @return True if a piece is found and removed. False otherwise. 
 * @note Since we require `type` and `color` to be uppercase, you need not transform it.
 */
bool ChessBox::removePiece(const std::string& type, const std::string& color) {
    if (color == P1_COLOR_) {
        return P1_BOX_.remove(type);
    } 
    else if (color == P2_COLOR_) {
        return P2_BOX_.remove(type);
    }
    return false;
}

/**
 * @brief Determines whether a ChessPiece of the given type 
 *        exists within the ArrayBox corresponding to the given color
 * 
 * @param type A const reference to an uppercase string 
 *             representing the type of the ChessPiece to find
 * @param color A const referene to an uppercase string 
 *              representing the color of the ChessPiece to find
 * 
 * @return True if a piece is contained within the correct ArrayBox. False otherwise. 
 * @note Since we require `type` and `color` to be uppercase, you need not transform it.
 */
bool ChessBox::contains(const std::string& type, const std::string &color) const {
    if (color == P1_COLOR_) {
        return P1_BOX_.contains(type);
    } 
    else if (color == P2_COLOR_) {
        return P2_BOX_.contains(type);
    }
    return false;
}