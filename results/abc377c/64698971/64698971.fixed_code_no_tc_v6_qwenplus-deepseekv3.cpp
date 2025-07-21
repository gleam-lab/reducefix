#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; int M;
    cin >> N >> M;

    set<pair<int, int>> attacked;
    set<pair<int, int>> pieces;

    // The 8 possible attack directions
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        pieces.insert({a, b});
        for (const auto &dir : directions) {
            int x = a + dir.first;
            int y = b + dir.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    // Total squares that are either occupied or under attack
    long long total_bad = pieces.size();
    for (const auto &pos : attacked) {
        if (pieces.find(pos) == pieces.end()) {
            total_bad++;
        }
    }

    long long total_squares = N * N;
    long long answer = total_squares - total_bad;
    cout << answer << endl;
}