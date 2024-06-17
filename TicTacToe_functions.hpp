#include <vector>

void show_game_board(const std::vector<std::vector<std::string>> &game_board);

void update_game_board(
    std::vector<std::vector<std::string>> &game_board,
    const int &player,
    const std::string &target
    );

void switch_player(int &player);

void greet();

void check_board_columns(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner);
void check_board_rows(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner);
void check_board_crosses(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner);
void check_winner(const std::vector<std::vector<std::string>> &game_board, const int &player, int &winner);