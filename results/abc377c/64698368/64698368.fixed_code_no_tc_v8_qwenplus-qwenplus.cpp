#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

using ll = long long;
using PII = pair<ll, ll>;
struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ll N;
    int M;
    cin >> N >> M;

    unordered_set<PII, hash_pair> attacked_or_occupied;

    vector<PII> offsets = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;

        // Add the occupied cell
        attacked_or_occupied.insert({a, b});

        // Mark cells that this piece can attack
        for (auto [dx, dy] : offsets) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                attacked_or_occupied.insert({nx, ny});
            }
        }
    }

    // Total number of cells is N*N
    // Subtract number of cells that are either occupied or attacked
    cout << (N * N - (ll)attacked_or_occupied.size()) << endl;

    return 0;
}