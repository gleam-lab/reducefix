#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<pair<int, int>> pieces(M);
    for (int i = 0; i < M; ++i) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    // Define areas that can be captured by a piece
    vector<pair<int, int>> capture_areas[8] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Use a set to keep track of all captured squares
    set<pair<int, int>> captured_squares;

    for (const auto& piece : pieces) {
        for (const auto& area : capture_areas) {
            int x = piece.first + area.first;
            int y = piece.second + area.second;
            if (x > 0 && x <= N && y > 0 && y <= N) {
                captured_squares.insert({x, y});
            }
        }
    }

    // Calculate the total number of empty squares and subtract the captured squares
    long long total_squares = N * N;
    long long captured_count = captured_squares.size();
    cout << (total_squares - captured_count) << endl;

    return 0;
}