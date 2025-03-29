#include "Pawn.hpp"

/**
 * @brief Default Constructor. All boolean values are default initialized to false.
 * @note Remember to default construct the base-class as well
 * @post Sets the piece_size_ member to 1. Sets the type to "PAWN"
 */
Pawn::Pawn() : ChessPiece(), double_jumpable_{false} { setSize(1); setType("PAWN"); }

/**
* @brief Parameterized constructor.
* @param : A const reference to the color of the Pawn (a string). Set the color "BLACK" if the provided string contains non-alphabetic characters. 
*     If the string is purely alphabetic, it is converted and stored in uppercase
* @param : The 0-indexed row position of the Pawn (as a const reference to an integer). Default value -1 if not provided, or if the value provided is outside the board's dimensions, [0, BOARD_LENGTH)
* @param : The 0-indexed column position of the Pawn (as a const reference to an integer). Default value -1 if not provided, or if the value provided is outside the board's dimensions, [0, BOARD_LENGTH)
* @param : A flag indicating whether the Pawn is moving up on the board, or not (as a const reference to a boolean). Default value false if not provided.
* @param : A flag indicating whether the Pawn can double jump two spaces forward or not (as a const reference to a boolean). Default value false if not provided.
* @post : The private members are set to the values of the corresponding parameters. 
*   If either of row or col are out-of-bounds and set to -1, the other is also set to -1 (regardless of being in-bounds or not).
*   The piece_size_ member is set to 1
*   The type member is set to "PAWN"
*/
Pawn::Pawn(const std::string& color, const int& row, const int& col, const bool& movingUp, const bool& double_jumpable) :
    ChessPiece(color, row, col, movingUp, 1, "PAWN"), double_jumpable_{double_jumpable} {}

/**
 * @brief Gets the value of the flag for the Pawn can double jump
 * @return The boolean value stored in double_jumpable_
 */
bool Pawn::canDoubleJump() const {
    return double_jumpable_;
}

/**
 * @brief Toggles the double_jumpable_ flag of the Pawn
 * @post Sets the double_jumpable_ flag to opposite of its current value
 */
void Pawn::toggleDoubleJump() {
    double_jumpable_ = !double_jumpable_;
}

/**
 * @brief Determines if this pawn can be promoted to another piece
 *     A pawn can be promoted if its row has reached the farthest row it can move up (or down) to. This is determined by the board size and the Piece's movingUp_ member.
 *
 *     EXAMPLE: If a pawn is movingUp and the board has 8 rows, then it can promoted only if it is in the 7th row (0-indexed)
 * @return True if this pawn can be promoted. False otherwise.
 */
bool Pawn::canPromote() const {
    return (isMovingUp() && getRow() == BOARD_LENGTH - 1) || 
        (!isMovingUp() && getRow() == 0);
}