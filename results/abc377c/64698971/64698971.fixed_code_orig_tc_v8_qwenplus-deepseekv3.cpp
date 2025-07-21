#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> existing_pieces;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        existing_pieces.insert({a, b});
        for (const auto &move : moves) {
            long long x = a + move.first;
            long long y = b + move.second;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long attacked_count = attacked.size();
    long long existing_count = existing_pieces.size();

    // Positions that are either occupied or under attack
    for (const auto &piece : existing_pieces) {
        if (attacked.count(piece)) {
            attacked_count--;
        }
    }

    long long safe_positions = total - attacked_count - existing_count;
    cout << safe_positions << endl;

    return 0;
}