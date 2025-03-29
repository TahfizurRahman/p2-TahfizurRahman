#include "ChessBox.hpp"

/**
 * Default constructor
 * Default initializes P1_COLOR_ to "BLACK" and P2_COLOR_ to "WHITE"
 * Initializes LinkedBox members with capacity 64
 */
ChessBox::ChessBox() : P1_COLOR_{"BLACK"}, P2_COLOR_{"WHITE"}, P1_BOX_{LinkedBox<ChessPiece>()}, P2_BOX_{LinkedBox<ChessPiece>()}{}

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
ChessBox::ChessBox(const std::string& color1, const std::string& color2, int capacity) : 
   P1_COLOR_{"BLACK"}, P2_COLOR_{"WHITE"}, P1_BOX_{LinkedBox<ChessPiece>(capacity)}, P2_BOX_{LinkedBox<ChessPiece>(capacity)}{

      std::string color1_uppercase, color2_uppercase;

      for (size_t i = 0; i < color1.size() && std::isalpha(color1[i]); i++) { color1_uppercase += std::toupper(color1[i]); } 
      for (size_t i = 0; i < color2.size() && std::isalpha(color2[i]); i++) { color2_uppercase += std::toupper(color2[i]); } 

      // If all param characters are successfully converted to uppercase, we use it
      if (color1_uppercase.size() != color1.size() || color2_uppercase.size() != color2.size()) { return; }
      if (color1_uppercase == color2_uppercase) { return; }

      P1_COLOR_ = std::move(color1_uppercase);
      P2_COLOR_ = std::move(color2_uppercase);
}
/**
 * @brief Getter for P1_BOX
 * @return The LinkedBox<ChessPiece> (ie. the value) of P1_BOX_
 */
LinkedBox<ChessPiece> ChessBox::getP1Pieces() const {
   return P1_BOX_;
}

/**
 * @brief Getter for P2_BOX
 * @return The LinkedBox<ChessPiece> (ie. the value) of P2_BOX_
 */
LinkedBox<ChessPiece> ChessBox::getP2Pieces() const {
   return P2_BOX_;
}
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
bool ChessBox::addPiece(const ChessPiece& piece) {
   LinkedBox<ChessPiece>* match = nullptr;
   
   if (piece.getColor() == P1_COLOR_) { 
      match = &P1_BOX_;
   } else if (piece.getColor() == P2_COLOR_) {
      match = &P2_BOX_;
   }

   if (match == nullptr) { return false; }
   return match->addItem(piece);
}

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
bool ChessBox::removePiece(const std::string& type, const std::string& color) {
   LinkedBox<ChessPiece>* match = nullptr;
   
   if (color == P1_COLOR_) { 
      match = &P1_BOX_;
   } else if (color == P2_COLOR_) {
      match = &P2_BOX_;
   }

   if (match == nullptr) { return false; }
   return match->remove(type);
}


/**
 * @brief Finds whether a ChessPiece of the given type exists within the LinkedBox corresponding to the given color
 * 
 * @param type A const reference to an uppercase string 
 *             representing the type of the ChessPiece to find
 * @param color A const referene to an uppercase string 
 *             representing the color of the ChessPiece to find
 * @return True if a piece is contained within the correct LinkedBox. False otherwise. 
 */
bool ChessBox::contains(const std::string& type, const std::string &color) const {
   return (color == P1_COLOR_ && P1_BOX_.contains(type)) ||  (color == P2_COLOR_ && P2_BOX_.contains(type));
}



/**
* @brief Getter for P1_COLOR_
* @return The string value stored in P1_COLOR_
*/
std::string ChessBox::getP1Color() const {
   return P1_COLOR_;
}

/**
* @brief Getter for P2_Color
* @return The string value stored in P2_COLOR
*/
std::string ChessBox::getP2Color() const {
   return P2_COLOR_;
}