#include <complex.h>
#include <iostream>
#include <vector>

void show_game_board(const std::vector<std::vector<std::string>> &game_board)
{
    for (int i=0; i<3; i++) {
        std::cout << " " << game_board[i][0] << " |";
        std::cout << " " << game_board[i][1] << " |";
        std::cout << " " << game_board[i][2] << " \n";
        if (i<2) {
            std::cout << "----|----|-----\n";
        }
    }
}

void update_game_board(std::vector<std::vector<std::string>> &game_board, const int &player, const std::string &target)
{
    std::string value;
    if (player == 1)
    {
        value = " O";
    } else
    {
        value = " X";
    }
    int target_column = target[1] - '0' - 1;
    int target_row = std::toupper(target[0]) - 64 - 1; // gets position in alphabet

    if (target_row > 2 || target_column > 2) {
        std::cout << "Sorry, that's not a valid input, please try again: ";
        } else
        {
            game_board[target_row][target_column] = value;
        }
    
}

void greet()
{
    std::cout << "XOXOXOXOXOXO\n";
    std::cout << "Tic-Tac-Toe\n";
    std::cout << "XOXOXOXOXOXO\n";
    std::cout << "Instructions: Player 1 and Player 2 take turns entering the position of their move\n";
    std::cout << "player 1: O\n";
    std::cout << "player 2: X\n";
    std::cout << "The first to get three in a row in any direction wins!\n";
}

void switch_player(int &player)
{
    if (player == 1)
    {
        player ++;
    } else
    {
        player --;
    }
}

void check_board_rows(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner)
{
    for (int i=0; i < game_board.size(); i++)
    {
        if (game_board[i][0] == game_board[i][1] && game_board[i][0] == game_board[i][2])
        {
            winner = player;
        }
    }
}
void check_board_columns(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner)
{
    for (int i=0; i < game_board.size(); i++)
    {
        if (game_board[0][i] == game_board[1][i] && game_board[0][i] == game_board[2][i])
        {
            winner = player;
        }
    }
}
void check_board_crosses(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner)
{
    if (game_board[0][0] == game_board[1][1] && game_board[0][0] == game_board[2][2])
    {
        winner = player;
    }
    if (game_board[0][2] == game_board[1][1] && game_board[0][0] == game_board[2][0])
    {
        winner = player;
    }
}


void check_winner(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner)
{
    check_board_columns(game_board, player, winner);
    check_board_rows(game_board, player, winner);
    check_board_crosses(game_board, player, winner);
}