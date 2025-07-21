#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> threatened;
    set<pair<long long, long long>> occupied;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
        for (auto [dx, dy] : moves) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                threatened.insert({x, y});
            }
        }
    }

    long long total_squares = N * N;
    long long unsafe_squares = threatened.size() + occupied.size();

    // Subtract the squares that are both occupied and threatened (to avoid double counting)
    for (auto [a, b] : occupied) {
        if (threatened.count({a, b})) {
            unsafe_squares--;
        }
    }

    long long safe_squares = total_squares - unsafe_squares;
    cout << safe_squares << endl;

    return 0;
}