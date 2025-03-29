#pragma once

#include "LinkedBox.hpp"
#include "ChessPiece.hpp"
#include <cctype>
#include <utility>

class ChessBox {
    private: 
        std::string P1_COLOR_, P2_COLOR_;
        LinkedBox<ChessPiece> P1_BOX_, P2_BOX_;

    public:
        /**
         * Default constructor
         * Default initializes P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
         * Initializes LinkedBox members with capacity 64
         */
        ChessBox();

        /**
         * Paramaterized Constructor
         * @param color1 A const reference to the color of the Chess Piece (a string)
         * @param color2 A const reference to the color of the Chess Piece (a string)
         * @param capacity An integer describing the 
         *                 capacity of each player's LinkedBox, with default capacity 64.
         * 
         * @note 1) If either color1 or color2 contains 
         *       non-alphabetic characters, set P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
         *       2) Otherwise, if the string is purely alphabetic, 
         *          it is converted and stored in uppercase.* 
         *       3) However, if the are equal, set color1 to "BLACK" and color2 to "WHITE"
         *       4) If the specified capacity is not positive (ie. <= 0), 64 is used instead.
         * 
         * @post Initializes LinkedBox members with the specified capacity. 
         *       All strings are initialized as described above. 
         */
        ChessBox(const std::string& color1, const std::string& color2, int capacity = 64);
        /**
         * @brief Getter for P1_BOX
         * @return The LinkedBox<ChessPiece> (ie. the value) of P1_BOX_
         */
        LinkedBox<ChessPiece> getP1Pieces() const;

        /**
         * @brief Getter for P2_BOX
         * @return The LinkedBox<ChessPiece> (ie. the value) of P2_BOX_
         */ 
        LinkedBox<ChessPiece> getP2Pieces() const;
        /**
         * @brief Adds a given ChessPiece object to the LinkedBox corresponding to its color:
         *      - If the color of the given piece matches P1_COLOR_, add it to P1_BOX_
         *      - If the color of the given piece matches P2_COLOR_, add it to P2_BOX_
         *      - If the color does not match either box, or the corresponding 
         *           box doesn't have enough remaining space to add the piece, 
         *           the add operation fails.
         * 
         * @param piece A const reference to a ChessPiece object that is to be added to one of the LinkedBoxes
         * @return True if the piece was added successfully. False otherwise.
         *
         */
        bool addPiece(const ChessPiece& piece);
        
        /**
         * @brief Removes a ChessPiece of the given type if one 
         *        exists in the LinkedBox corresponding to the given color
         * 
         * @param type A const reference to an uppercase string 
         *             representing the type of the ChessPiece to remove
         * @param color A const referene to an uppercase string 
         *              representing the color of the ChessPiece to remove
         * @return True if a piece is found and removed. False otherwise. 
         */
        bool removePiece(const std::string& type, const std::string& color);

        /**
         * @brief Finds whether a ChessPiece of the given type exists within the LinkedBox corresponding to the given color
         * 
         * @param type A const reference to an uppercase string 
         *             representing the type of the ChessPiece to find
         * @param color A const referene to an uppercase string 
         *             representing the color of the ChessPiece to find
         * @return True if a piece is contained within the correct LinkedBox. False otherwise. 
         */
        bool contains(const std::string& type, const std::string &color) const;

        /**
         * @brief Getter for P1_Color
         * @return The string value stored in P1_COLOR
         */
        std::string getP1Color() const;

        /**
         * @brief Getter for P2_Color
         * @return The string value stored in P2_COLOR
         */
        std::string getP2Color() const;
};