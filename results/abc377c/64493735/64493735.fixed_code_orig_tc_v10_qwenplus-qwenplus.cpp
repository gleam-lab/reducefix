#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    int M;
    cin >> N >> M;

    // Use a pair hash function for unordered_set
    using pii = pair<int64_t, int64_t>;
    struct PairHash {
        size_t operator()(const pii& p) const {
            return hash<int64_t>{}(p.first) ^ (hash<int64_t>{}(p.second) << 32);
        }
    };

    unordered_set<pii, PairHash> forbidden;

    vector<pii> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int64_t a, b;
        cin >> a >> b;
        forbidden.insert({a, b});

        for (auto [dx, dy] : offsets) {
            int64_t x = a + dx;
            int64_t y = b + dy;
            if (1 <= x && x <= N && 1 <= y && y <= N) {
                forbidden.insert({x, y});
            }
        }
    }

    cout << (N * N - forbidden.size()) << '\n';
}