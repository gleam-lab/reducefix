#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> occupied_or_attacked;

    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Convert to 0-based indexing
        a--; b--;
        occupied_or_attacked.insert({a, b});

        for (auto [dx, dy] : directions) {
            ll na = a + dx;
            ll nb = b + dy;
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                occupied_or_attacked.insert({na, nb});
            }
        }
    }

    // Total cells: N * N
    // Subtract the number of cells that are either occupied or attacked
    cout << (N * N - (ll)occupied_or_attacked.size()) << '\n';
}