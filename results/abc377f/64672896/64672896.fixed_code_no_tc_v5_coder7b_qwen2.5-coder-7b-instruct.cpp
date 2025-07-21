#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    set<pair<long long, long long>> pieces;
    vector<long long> rows(N+1, 0), cols(N+1, 0), diags(N+1, 0), anti_diags(N+1, 0);

    for (long long i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
        rows[a]++;
        cols[b]++;
        diags[a + b]++;
        anti_diags[a - b]++;
    }

    long long total_unsafe = 0;

    for (const auto& [a, b] : pieces) {
        total_unsafe += rows[a];
        total_unsafe += cols[b];
        total_unsafe += diags[a + b];
        total_unsafe += anti_diags[a - b];
    }

    // Remove double-counted intersections
    for (const auto& [a, b] : pieces) {
        total_unsafe -= rows[a] > 1;
        total_unsafe -= cols[b] > 1;
        total_unsafe -= diags[a + b] > 1;
        total_unsafe -= anti_diags[a - b] > 1;
    }

    // Total valid squares
    long long valid_squares = N * N - total_unsafe;
    cout << valid_squares << endl;

    return 0;
}