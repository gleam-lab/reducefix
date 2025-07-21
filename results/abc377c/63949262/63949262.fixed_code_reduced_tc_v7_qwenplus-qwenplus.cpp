#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

// Hash specialization for pair<ll, ll>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 16); // Combine hashes
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    unordered_set<pll, hash_pair> blocked;

    vector<pair<ll, ll>> deltas = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;

        blocked.insert({a, b});

        for (auto [dx, dy] : deltas) {
            ll nx = a + dx;
            ll ny = b + dy;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                blocked.insert({nx, ny});
            }
        }
    }

    cout << (N * NLL - (ll)blocked.size()) << endl;

    return 0;
}