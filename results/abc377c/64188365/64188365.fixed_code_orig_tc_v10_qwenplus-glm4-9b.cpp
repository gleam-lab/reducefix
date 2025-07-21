#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> pieces(m);
    set<pair<long long, long long>> all_tiles, captured_tiles;

    for (long long i = 0; i < m; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
        all_tiles.insert(pieces[i]);
    }

    // Define capture range relative to a piece's position
    auto can_capture = [&](const pair<long long, long long>& piece) {
        vector<pair<long long, long long>> capture_range = {
            {piece.first + 2, piece.second + 1},
            {piece.first + 1, piece.second + 2},
            {piece.first - 1, piece.second + 2},
            {piece.first - 2, piece.second + 1},
            {piece.first - 2, piece.second - 1},
            {piece.first - 1, piece.second - 2},
            {piece.first + 1, piece.second - 2},
            {piece.first + 2, piece.second - 1}
        };

        for (const auto& tile : capture_range) {
            if (tile.first < 1 || tile.first > n || tile.second < 1 || tile.second > n)
                continue; // Skip out-of-bound tiles
            if (all_tiles.count(tile))
                captured_tiles.insert(tile);
        }
    };

    // Process each piece
    for (const auto& piece : pieces) {
        auto neighbors = {
            {piece.first + 2, piece.second + 1}, {piece.first + 1, piece.second + 2},
            {piece.first - 1, piece.second + 2}, {piece.first - 2, piece.second + 1},
            {piece.first - 2, piece.second - 1}, {piece.first - 1, piece.second - 2},
            {piece.first + 1, piece.second - 2}, {piece.first + 2, piece.second - 1}
        };
        for (const auto& neighbor : neighbors) {
            if (all_tiles.count(neighbor) && captured_tiles.count(neighbor))
                can_capture(piece);
        }
    }

    // Calculate the number of available tiles
    long long available_tiles = n * n - captured_tiles.size();
    cout << available_tiles << endl;

    return 0;
}