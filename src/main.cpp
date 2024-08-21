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
    std::cout << "1. Spawn a piece" << std::endl;
    std::cout << "2. Move a piece" << std::endl;
    std::cout << "3. Print active pieces" << std::endl;
    std::cout << "0. Quit" << std::endl;
}

void spawn_piece_menu(Board &board)
{
    char piece_type;
    char piece_color;
    std::string position_input;
    int row = -1, col = -1;

    std::cout << "Select piece to spawn <P: Pawn, N: Knight, B: Bishop, R: Rook, Q: Queen, K: King>: ";
    std::cin >> piece_type;

    std::cout << "Select piece color <w: White, b: Black>: ";
    std::cin >> piece_color;

    // Clear the newline left in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter position <row, column>: ";
    std::getline(std::cin, position_input);

    // Parse the input string
    std::istringstream iss(position_input);
    char comma;

    if (iss >> row >> comma >> col && comma == ',')
    {
        Position pos{row, col};
        board.spawn_piece(static_cast<PieceType>(toupper(piece_type)),
                          static_cast<PieceColor>(tolower(piece_color)),
                          pos);
    }
    else
    {
        std::cout << "Invalid input format: Please enter two comma-seperated integers in the range 1-8 <row, column>." << std::endl;
    }
}

void move_piece_menu(Board &board)
{
    std::string start_input, end_input;
    int start_row = -1, start_col = -1;
    int end_row = -1, end_col = -1;

    // Get and validate start position input
    std::cout << "Enter start position <row, column>: ";
    std::getline(std::cin >> std::ws, start_input); // std::ws discards leading whitespace

    std::istringstream start_stream(start_input);
    char start_comma;

    if (!(start_stream >> start_row >> start_comma >> start_col) || start_comma != ',')
    {
        std::cout << "Invalid input format: Please enter two comma-seperated integers in the range 1-8 <row, column>." << std::endl;
        return;
    }

    // Get and validate end position input
    std::cout << "Enter end position <row, column>: ";
    std::getline(std::cin, end_input);

    std::istringstream end_stream(end_input);
    char end_comma;

    if (!(end_stream >> end_row >> end_comma >> end_col) || end_comma != ',')
    {
        std::cout << "Invalid input format: Please enter two comma-seperated integers in the range 1-8 <row, column>." << std::endl;
        return;
    }

    Position start{start_row, start_col};
    Position end{end_row, end_col};

    board.move_piece(start, end);
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
            spawn_piece_menu(board);
            break;
        case 2:
            move_piece_menu(board);
            break;
        case 3:
            board.print_active_pieces();
            break;
        case 0:
            std::cout << "Quitting the game..." << std::endl;
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
 * Main function with a hardcoded test case
 */
// int main()
// {
//     Board board;
//     board.draw();

//     // board.spawn_piece('N', 'b', Position(1, 1));
//     board.spawn_piece(PieceType::Knight, PieceColor::Black, Position(1, 1));
//     board.move_piece(Position(1, 1), Position(1, 5));
//     // board.spawn_piece('N', 'b', Position(1, 2));
//     // board.spawn_piece('N', 'b', Position(1, 3));
//     // board.spawn_piece('N', 'w', Position(2, 1));
//     // board.spawn_piece('N', 'w', Position(2, 2));
//     // board.spawn_piece('N', 'w', Position(2, 3));
//     // board.spawn_piece('Q', 'w', Position(1, 2));
//     // board.spawn_piece('B', 'b', Position(1, 2));
//     board.print_active_pieces();
//     board.draw();

//     // board.spawn_piece('R', 'b', Position(2, 1));
//     // board.spawn_piece('R', 'b', Position(2, 1));
//     // board.spawn_piece('R', 'b', Position(2, 2));
//     // // board.spawn_piece('B', 'b', Position(1, 2));
//     // board.print_active_pieces();
//     // board.draw();

//     // board.move_piece(Position(1, 1), Position(1, 5));
//     // board.draw();

//     // board.move_piece(Position(1, 1), Position(5, 1));
//     // board.draw();

//     // board.move_piece(Position(1, 1), Position(3, 1));
//     // board.draw();

//     // board.move_piece(Position(5, 1), Position(2, 3));
//     // board.draw();

//     // board.move_piece(Position(5, 1), Position(5, 6));
//     // board.draw();

//     // board.move_piece(Position(1, 2), Position(1, 1));
//     // board.draw();

//     // board.move_piece(Position(1, 2), Position(2, 3));
//     // board.draw();

//     // board.move_piece(Position(2, 3), Position(5, 6));
//     // board.draw();

//     // board.move_piece(Position(2, 3), Position(-1, 0));
//     // board.draw();

//     // board.print_active_pieces();

//     std::cout << std::endl;
//     return 0;
// }
