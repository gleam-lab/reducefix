#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    // Set to store positions of existing pieces and attacked squares
    unordered_set<long long> attacked;
    auto hash = [&](long long x, long long y) { return (x << 32) | y; };

    vector<pair<long long, long long>> pieces(M);
    for (int i = 0; i < M; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // The 8 possible L-shaped moves of a knight-like piece
    vector<pair<long long, long long>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (auto [a, b] : pieces) {
        for (auto [dx, dy] : directions) {
            long long x = a + dx;
            long long y = b + dy;
            if (x >= 1 && x <= N && y >= 1 && y <= N) {
                attacked.insert(hash(x, y));
            }
        }
    }

    // Subtract the number of attacked or occupied cells from total
    long long total_cells = N * N;
    long long blocked = M + attacked.size();
    cout << total_cells - blocked << endl;

    return 0;
}