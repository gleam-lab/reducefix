#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> occupied;
    set<pair<long long, long long>> attacked;

    vector<pair<long long, long long>> moves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        // Convert from 1-based to 0-based indices
        --a; --b;
        occupied.insert({a, b});
        attacked.insert({a, b}); // You can't place a piece here anyway

        for (auto [dx, dy] : moves) {
            long long na = a + dx;
            long long nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                attacked.insert({na, nb});
            }
        }
    }

    // Total positions = N*N
    // Subtract all positions that are either occupied or attacked
    cout << (N * N) - (long long)attacked.size() << endl;

    return 0;
}