#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> attacked;
    set<pair<long long, long long>> occupied;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        occupied.insert({a, b});
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                attacked.insert({x, y});
            }
        }
    }

    long long total = N * N;
    long long unsafe_attacked = attacked.size();
    long long occupied_count = occupied.size();

    // The safe squares are total - (attacked squares + occupied squares - squares that are both attacked and occupied)
    // But since occupied squares are not counted in attacked squares (pieces cannot attack their own positions),
    // the total unsafe is attacked squares + occupied squares.
    long long safe_squares = total - unsafe_attacked - occupied_count;

    cout << safe_squares << endl;

    return 0;
}