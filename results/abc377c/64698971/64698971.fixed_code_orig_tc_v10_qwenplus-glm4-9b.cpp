#include <iostream>
#include <vector>
#include <unordered_set>

// Function to check if a position is within grid boundaries
bool is_within_bounds(int r, int c, int N) {
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

// Function to find all possible captures from a given position
std::unordered_set<std::pair<int, int>> find_captures(int r, int c, int N) {
    std::unordered_set<std::pair<int, int>> captures;
    // Define capture positions based on the problem description
    // ...
    return captures;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    // Define the size of each block, for example, make it manageable
    const int BLOCK_SIZE = 10; // This might need to be adjusted based on N

    // Initialize total count of safe positions
    long long safe_positions = 0;

    // Check each block
    for (int block_r = 1; block_r <= N; block_r += BLOCK_SIZE) {
        for (int block_c = 1; block_c <= N; block_c += BLOCK_SIZE) {
            // Calculate the maximum grid to consider for the current block
            int max_r = min(block_r + BLOCK_SIZE - 1, N);
            int max_c = min(block_c + BLOCK_SIZE - 1, N);

            // For each position in the block
            for (int r = block_r; r <= max_r; ++r) {
                for (int c = block_c; c <= max_c; ++c) {
                    bool is_safe = true;

                    // Check if this position can be captured by any existing piece
                    for (const auto& piece : pieces) {
                        auto captures = find_captures(piece.first, piece.second, N);
                        if (captures.count({r, c})) {
                            is_safe = false;
                            break;
                        }
                    }

                    // If it's safe, increment the safe position count
                    if (is_safe) {
                        ++safe_positions;
                    }
                }
            }
        }
    }

    std::cout << safe_positions << std::endl;

    return 0;
}