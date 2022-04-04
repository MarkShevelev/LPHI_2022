#include <iostream>
#include <random>
#include <chrono>

enum class CellState {ALIVE, DEAD};           // by default the integer equivalents are 0, 1
enum class Direction {RIGHT, UP, LEFT, DOWN}; // integer equivalensts are 0, 1, 2, 3

using namespace std;

int main() {
    auto seed = static_cast<unsigned>(
        chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count()
    );
    default_random_engine rng(seed);
    uniform_int_distribution<int> direction_dstr(0,3);

    std::size_t const row_size = 11;
    std::size_t const col_size = 11;
    CellState cell_grid[row_size][col_size];

    // init
    for (std::size_t row_idx = 0; row_idx != row_size; ++row_idx)
        for (std::size_t col_idx = 0; col_idx != col_size; ++col_idx)
            cell_grid[row_idx][col_idx] = CellState::DEAD; // assign dead state to the all of the cells

    cell_grid[row_size / 2][col_size / 2] = CellState::ALIVE; // one cell is alive
    std::size_t dislocation_row_idx = row_size / 2;
    std::size_t dislocation_col_idx = col_size / 2;

    // run
    bool proceed = true;
    auto walk_cnt = 0ull;
    while (proceed) {
        auto random_direction = static_cast<Direction>(direction_dstr(rng)); // can cast integer to the enum
        switch(random_direction) { // we can use enums in a switch 
            case Direction::RIGHT:
                ++dislocation_col_idx;
            break;

            case Direction::UP:
                ++dislocation_row_idx;
            break;

            case Direction::LEFT:
                --dislocation_col_idx;
            break;

            case Direction::DOWN:
                --dislocation_row_idx;
            break;
        }
        ++walk_cnt;

        if (0 == dislocation_col_idx || col_size - 1 == dislocation_col_idx || 0 == dislocation_row_idx || row_size - 1 == dislocation_row_idx)
            proceed = false;
    }

    cout << walk_cnt << endl;
    return 0;
}