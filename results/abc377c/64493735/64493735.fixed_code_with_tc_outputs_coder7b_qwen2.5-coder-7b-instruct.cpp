#include <bits/stdc++.h>
using namespace std;

struct Sub {
    long long solve() {
        long long N, M;
        cin >> N >> M;

        // Set to store all positions that can be captured
        set<pair<long long, long long>> captured;

        for (long long i = 0; i < M; ++i) {
            long long a, b;
            cin >> a >> b;

            // Define all possible capturing positions
            vector<pair<long long, long long>> candidates = {
                {a + 2, b + 1},
                {a + 1, b + 2},
                {a - 1, b + 2},
                {a - 2, b + 1},
                {a - 2, b - 1},
                {a - 1, b - 2},
                {a + 1, b - 2},
                {a + 2, b - 1}
            };

            for (auto &[x, y] : candidates) {
                if (x >= 1 && x <= N && y >= 1 && y <= N) {
                    captured.emplace(x, y);
                }
            }
        }

        // Total empty cells minus captured cells
        return N * N - captured.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Sub sub;
    cout << sub.solve() << "\n";
}