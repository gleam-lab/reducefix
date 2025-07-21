#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> dangerous;

    vector<pair<ll, ll>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;

        for (const auto& dir : directions) {
            ll x = a + dir.first;
            ll y = b + dir.second;
            if (x >= 0 && x < N && y >= 0 && y < N) {
                dangerous.insert({x, y});
            }
        }
    }

    ll total_squares = N * N;
    ll occupied = M;
    ll dangerous_count = dangerous.size();
    ll safe_squares = total_squares - occupied - dangerous_count;

    cout << safe_squares << endl;

    return 0;
}