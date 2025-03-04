#include <iostream>
#include "ChessPiece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "ChessBox.hpp"

int main() {
    // Test ChessPiece
    ChessPiece piece1("WHITE", 0, 0, true);
    piece1.display();

    // Test Pawn
    Pawn pawn1("BLACK", 1, 1, false, true);
    pawn1.display();
    std::cout << "Pawn can double jump: " << pawn1.canDoubleJump() << std::endl;
    std::cout << "Pawn can promote: " << pawn1.canPromote() << std::endl;

    // Test Rook
    Rook rook1("WHITE", 7, 7, true, 3);
    rook1.display();
    std::cout << "Rook castle moves left: " << rook1.getCastleMovesLeft() << std::endl;

    // Test ChessBox
    ChessBox chessBox("BLACK", "WHITE", 16);

    // Add pieces to ChessBox
    Pawn pawn2("BLACK", 2, 2, false, false);
    Rook rook2("WHITE", 6, 6, false, 2);

    chessBox.addPiece(pawn1);
    chessBox.addPiece(rook1);
    chessBox.addPiece(pawn2);
    chessBox.addPiece(rook2);

    std::cout << "P1 Color: " << chessBox.getP1Color() << std::endl;
    std::cout << "P2 Color: " << chessBox.getP2Color() << std::endl;

    // Display pieces in ChessBox
    std::cout << "P1 Pieces: " << chessBox.getP1Pieces().size() << std::endl;
    std::cout << "P2 Pieces: " << chessBox.getP2Pieces().size() << std::endl;

    // Test contains function
    std::cout << "ChessBox contains BLACK PAWN: " << chessBox.contains("PAWN", "BLACK") << std::endl;
    std::cout << "ChessBox contains WHITE ROOK: " << chessBox.contains("ROOK", "WHITE") << std::endl;

    // Test remove function
    chessBox.removePiece("PAWN", "BLACK");
    std::cout << "After removing BLACK PAWN, P1 Pieces: " << chessBox.getP1Pieces().size() << std::endl;

    chessBox.removePiece("ROOK", "WHITE");
    std::cout << "After removing WHITE ROOK, P2 Pieces: " << chessBox.getP2Pieces().size() << std::endl;

    return 0;
}