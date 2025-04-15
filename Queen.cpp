// File: Queen.cpp
// Author: Tahfizur Rahman 
// Date: 04/15/2025
// A header files that defines queen
#include "Queen.hpp"

/**
 * @brief Default Constructor.
 * @post Sets piece_size_ to 9 and type to "QUEEN"
 */
Queen::Queen() : ChessPiece() { setSize(4); setType("QUEEN"); }

/**
 * @brief Parameterized constructor.
 * @param color: The color of the Queen.
 * @param row: 0-indexed row position of the Queen.
 * @param col: 0-indexed column position of the Queen.
 * @param movingUp: Flag indicating whether the Queen is moving up.
 */
Queen::Queen(const std::string& color, const int& row, const int& col, const bool& movingUp)
    : ChessPiece(color, row, col, movingUp, 4, "QUEEN") {}

// YOUR CODE HERE 
/**
 * @brief Determines whether the Queen can move to the specified target position on the board.
 * @pre The row & col members of the Queen object match its actual position on the passed board object.
 * 
 * The Queen's movement follows these rules:
 * 1. The Queen may move any number of squares
 *      vertically, horizontally, or diagonally from its current position
 * 2. The path to the target square must be unobstructed by (ie. contain) other pieces, 
 *      except for the target square itself.
 * 3. The target square must either be empty (moving) or contain a piece of another color (capturing)
 * 4. The target square must stay within the board's bounds, ie. not outside [0, BOARD_LENGTH)
 * 5. The Queen cannot move to its currently occupied position (i.e. it can't stand still).
 * 
 * @param target_row An integer representing the row index of the target square on the board.
 * @param target_col An integer representing the column index of the target square on the board.
 * @param board A 2D vector representing the current board state, 
 *              where each cell points to a ChessPiece object or is null.
 * 
 * @return True if the Queen can move to the specified position; false otherwise.
 */
bool Queen::canMove(const int& target_row, const int& target_col, const std::vector<std::vector<ChessPiece*>>& board) const {
    // Not on the board
    if (getRow() == -1 || getColumn() == -1) { return false; }
    
    // R1- Vertical, horizontal and diagonal
    int row_diff = target_row - getRow();
    int col_diff = target_col - getColumn();
    if (!(row_diff == 0 || col_diff == 0 || std::abs(row_diff) == std::abs(col_diff))) {
        return false; 

    // R2- Check path for obstructions
    int row_step = (row_diff == 0) ? 0 : (row_diff > 0 ? 1 : -1);
    int col_step = (col_diff == 0) ? 0 : (col_diff > 0 ? 1 : -1);
    int curr_row = getRow() + row_step;
    int curr_col = getColumn() + col_step;
    
    while (curr_row != target_row || curr_col != target_col) {
        if (board[curr_row][curr_col] != nullptr) { 
            return false; 
        }
        curr_row += row_step;
        curr_col += col_step;
    }
    // R3
    ChessPiece* target_piece = board[target_row][target_col];
    if (target_piece && target_piece->getColor() == getColor()) { 
        return false; 
    }
    // R4
    if (target_row < 0 || target_row >= BOARD_LENGTH || target_col < 0 || target_col >= BOARD_LENGTH) { 
        return false; 
    }
    // R5
    if (getRow() == target_row && getColumn() == target_col) {
        return false;
    }
    
    return true;
}