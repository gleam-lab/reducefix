#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> pieces(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    // Using maps to track the positions in rows, columns, diagonals, and anti-diagonals
    std::map<int, int> row_positions, col_positions, diag_positions, anti_diag_positions;

    // Fill maps with the positions of the pieces
    for (const auto& p : pieces) {
        row_positions[p.first]++;
        col_positions[p.second]++;
        diag_positions[p.first + p.second]++;
        anti_diag_positions[p.first - p.second]++;
    }

    // Calculate the number of positions that can be captured by existing pieces
    long long captured_positions = row_positions.size() * n +
                                    col_positions.size() * n +
                                    diag_positions.size() * n +
                                    anti_diag_positions.size() * n;

    // Calculate the total number of empty squares
    long long total_empty_squares = n * n;

    // Calculate the number of squares where you can place your piece
    long long safe_squares = total_empty_squares - captured_positions;

    // Output the result
    std::cout << safe_squares << std::endl;

    return 0;
}