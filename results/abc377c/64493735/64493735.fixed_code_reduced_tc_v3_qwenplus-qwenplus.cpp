#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int M;
    cin >> N >> M;

    unordered_set<long long> attacked;
    auto hash = [&](int x, int y) {
        return (x - 1LL) * N + (y - 1LL);
    };

    // Store positions of existing pieces to avoid placing on them
    unordered_set<long long> pieces;

    for (int k = 0; k < M; ++k) {
        int a, b;
        cin >> a >> b;
        pieces.insert(hash(a, b));
    }

    // For each piece, mark all squares it can attack
    for (auto it = pieces.begin(); it != pieces.end(); ++it) {
        long long h = *it;
        int a = (h / N) + 1;
        int b = (h % N) + 1;

        const vector<pair<int, int>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (const auto& [dx, dy] : moves) {
            int na = a + dx;
            int nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                attacked.insert(hash(na, nb));
            }
        }
    }

    // Total squares that are either occupied or under attack
    long long total_bad = pieces.size() + attacked.size();

    // The result is total squares minus bad squares
    cout << (N * N - total_bad) << endl;

    return 0;
}