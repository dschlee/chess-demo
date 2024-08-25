#include <iostream>
#include <cctype>
#include <sstream>
#include <limits>
#include "../lib/board.hpp"
#include "../lib/piece.hpp"
#include "../lib/pawn.hpp"
#include "../lib/knight.hpp"
#include "../lib/bishop.hpp"
#include "../lib/rook.hpp"
#include "../lib/queen.hpp"
#include "../lib/king.hpp"

void show_menu()
{
    std::cout << "Select an option:" << std::endl;
    std::cout << "1. Move a piece" << std::endl;
    std::cout << "2. Spawn a piece" << std::endl;
    std::cout << "3. Remove a piece" << std::endl;
    std::cout << "4. Print active pieces" << std::endl;
    std::cout << "0. Quit" << std::endl;
}

void move_piece_menu(Board &board)
{
    std::string start_input, end_input;

    // Get and validate start position input
    std::cout << "Enter start position in algebraic notation (e.g. a2) <column row>: ";
    std::getline(std::cin >> std::ws, start_input); // std::ws discards leading whitespace

    if (start_input.length() != 2 ||
        start_input[0] < 'a' || start_input[0] > 'h' ||
        start_input[1] < '1' || start_input[1] > '8')
    {
        std::cout << "Invalid input format: Please enter a valid chess position (column: a-h, row: 1-8)." << std::endl;
        return;
    }

    // Get and validate end position input
    std::cout << "Enter end position in algebraic notation (e.g. a4) <column row>: ";
    std::getline(std::cin, end_input);

    if (end_input.length() != 2 ||
        end_input[0] < 'a' || end_input[0] > 'h' ||
        end_input[1] < '1' || end_input[1] > '8')
    {
        std::cout << "Invalid input format: Please enter a valid chess position (column: a-h, row: 1-8)." << std::endl;
        return;
    }

    Position start{start_input};
    Position end{end_input};

    board.move_piece(start, end);
}

void spawn_piece_menu(Board &board)
{
    char piece_type;
    char piece_color;
    std::string position_input;

    std::cout << "Select piece to spawn <P: Pawn, N: Knight, B: Bishop, R: Rook, Q: Queen, K: King>: ";
    std::cin >> piece_type;

    std::cout << "Select piece color <w: White, b: Black>: ";
    std::cin >> piece_color;

    // Clear the newline left in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter position in algebraic notation (e.g. a2) <column row>: ";
    std::getline(std::cin, position_input);

    // Convert position from algebraic notation to numeric position
    if (position_input.length() == 2 &&
        position_input[0] >= 'a' && position_input[0] <= 'h' &&
        position_input[1] >= '1' && position_input[1] <= '8')
    {
        Position pos(position_input);
        board.spawn_piece(static_cast<PieceType>(toupper(piece_type)),
                          static_cast<PieceColor>(tolower(piece_color)),
                          pos);
    }
    else
    {
        std::cout << "Invalid input format: Please enter a valid chess position (column: a-h, row: 1-8)." << std::endl;
    }
}

void remove_piece_menu(Board &board)
{
    // TODO
    std::cout << "TODO" << std::endl;
}

/**
 * Main function that allows interaction with the menu
 */
int main()
{
    Board board;
    board.draw();

    int choice;
    do
    {
        show_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Catch the case where the input is not an integer
        while (std::cin.fail())
        {
            std::cin.clear();                                                   // clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the input
            std::cout << "Invalid input, please enter a number.";
            board.draw();
            show_menu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;
        }

        switch (choice)
        {
        case 1:
            move_piece_menu(board);
            break;
        case 2:
            spawn_piece_menu(board);
            break;
        case 3:
            remove_piece_menu(board);
            break;
        case 4:
            board.print_active_pieces();
            break;
        case 0:
            std::cout << "Quitting the game..." << std::endl
                      << std::endl;
            break;
        default:
            std::cout << "Invalid choice, please try again." << std::endl;
            break;
        }

        if (choice != 0)
        {
            board.draw();
        }

    } while (choice != 0);

    return 0;
}

/**
 * Main function that allows interaction with the menu
 */
// int main()
// {
// Board board;
// board.draw();

// board.spawn_piece(PieceType::Rook, PieceColor::White, Position("c2"));
// board.spawn_piece(PieceType::Bishop, PieceColor::Black, Position("b1"));
// board.print_active_pieces();
// board.draw();

// board.move_piece(Position("c2"), Position("j4"));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position("b1"), Position("c-1"));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(1, 1), Position(3, 1));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(5, 1), Position(2, 3));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(5, 1), Position(5, 6));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(1, 2), Position(1, 1));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(1, 2), Position(2, 3));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(2, 3), Position(5, 6));
// board.draw();
// board.print_active_pieces();

// board.move_piece(Position(2, 3), Position(-1, 0));
// board.draw();
// board.print_active_pieces();

//     std::cout << std::endl;
//     return 0;
// }
