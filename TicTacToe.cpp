#include <complex.h>
#include <iostream>
#include <vector>
#include "TicTacToe_functions.hpp"
int main(int argc, char* argv[])
{
    greet();
    std::string target;
    int player = 1;
    int winner = 0;
    
    std::vector<std::vector<std::string>> game_board{
        {"A1", "A2", "A3"},
        {"B1", "B2", "B3"},
        {"C1", "C2", "C3"},
    };
    
    std::cout << "Player 1 goes first!\n";
    
    while (winner == 0)
    {
        std::cout << "----------------\n";
        std::cout << "Player " << player << "'s turn!\n";
        show_game_board(game_board);
        std::cout << "Player " << player << " choose a square: ";
        std::cin >> target;
    
        update_game_board(game_board, player, target);
        
        show_game_board(game_board);
        std::cout << "Player " << player << " chose " << target << "\n";
        switch_player(player);
        
        check_winner(game_board, player, winner);
        
    }
    std::cout << "Player " << winner << " wins!";
    
    return 0;
}


