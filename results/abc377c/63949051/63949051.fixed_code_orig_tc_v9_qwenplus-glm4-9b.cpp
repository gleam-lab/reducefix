#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    set<pair<int, int>> attack_positions;

    // Compute attack positions for each piece
    for (const auto& piece : pieces) {
        int x = piece.first;
        int y = piece.second;

        // Add all possible attack positions
        attack_positions.insert({x + 2, y + 1});
        attack_positions.insert({x + 1, y + 2});
        // ... add other possible positions

        // // Add positions for cases like x, y + 2
        // if (x - 2 >= 1) attack_positions.insert({x - 2, y + 2});
        // if (y - 2 >= 1) attack_positions.insert({x + 1, y - 2});
        // ... add more cases
    }

    // Calculate the number of valid positions
    int valid_positions = 0;
    for (int x = 1; x <= N; ++x) {
        for (int y = 1; y <= N; ++y) {
            if (attack_positions.find({x, y}) == attack_positions.end()) {
                ++valid_positions;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}