#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

using ll = long long;
using pii = pair<int, int>;

// Hash function for pair<int, int>
struct PairHash {
    size_t operator()(const pii& p) const {
        return hash<int>()(p.first) ^ ((size_t)hash<int>()(p.second) << 16);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pii, PairHash> attacked;

    // All 8 possible attack offsets
    vector<pii> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        // Convert to 0-based index
        --a; --b;

        // Add current piece position to attacked set
        attacked.insert({a, b});

        // Add all positions that this piece can attack
        for (auto [dx, dy] : offsets) {
            ll nx = (ll)a + dx;
            ll ny = (ll)b + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                attacked.insert({(int)nx, (int)ny});
            }
        }
    }

    // Total number of cells is N*N
    // Subtract the number of attacked cells
    cout << N * N - (ll)attacked.size() << endl;

    return 0;
}