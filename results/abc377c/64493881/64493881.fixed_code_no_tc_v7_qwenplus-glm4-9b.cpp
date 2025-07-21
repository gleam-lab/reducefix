#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;

ll solve() {
    ll N, M;
    scanf("%lld %lld", &N, &M);

    vector<pair<ll, ll>> pieces(M);
    for (ll i = 0; i < M; ++i) {
        scanf("%lld %lld", &pieces[i].first, &pieces[i].second);
    }

    // Iterate over all possible positions
    ll count = 0;
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j <= N; ++j) {
            bool can_place = true;
            // Check if the current position can be captured by any piece
            for (ll k = 0; k < M; ++k) {
                ll a = pieces[k].first;
                ll b = pieces[k].second;

                // Directions a piece can capture
                vector<pair<ll, ll>> capture_positions = {
                    {a + 2, b + 1}, {a + 1, b + 2}, {a - 1, b + 2},
                    {a - 2, b + 1}, {a - 2, b - 1}, {a - 1, b - 2},
                    {a + 1, b - 2}, {a + 2, b - 1}
                };

                for (auto pos : capture_positions) {
                    if (pos.first >= 1 && pos.first <= N && pos.second >= 1 && pos.second <= N) {
                        if (pos == make_pair(i, j)) {
                            can_place = false;
                            break;
                        }
                    }
                }
            }

            if (can_place) {
                count = (count + 1) % mod;
            }
        }
    }

    // Output the count of valid positions
    printf("%lld\n", count);

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}