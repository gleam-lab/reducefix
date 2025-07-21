#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int N, M;
set<pair<int, int>> all_blocks, possible_blocks;

void insert_blocks(int a, int b) {
    // We need to consider the capturing range of each piece
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (abs(i) + abs(j) <= 2) {  // The piece captures if the distance is within the range
                int ai = a + i;
                int aj = b + j;
                if (ai >= 0 && ai < N && aj >= 0 && aj < N) {
                    // Check if the new block is already captured by another piece
                    if (!all_blocks.count({ai, aj})) {
                        possible_blocks.insert({ai, aj});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vector<pair<int, int>> pieces;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces.push_back({a - 1, b - 1});  // Subtract 1 to convert to 0-based index
    }

    // Insert the initial pieces into the all_blocks set
    for (auto p : pieces) {
        all_blocks.insert(p);
    }

    // Insert all possible blocks for each piece
    for (auto p : pieces) {
        insert_blocks(p.first, p.second);
    }

    // Calculate the number of empty squares
    long long empty_squares = N * N - all_blocks.size();
    cout << empty_squares << endl;

    return 0;
}