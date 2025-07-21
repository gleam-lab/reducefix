#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll pow_mod(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    unordered_set<ll> occupied;
    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        --x; --y;
        for (ll dx = -2; dx <= 2; ++dx) {
            for (ll dy = -2; dy <= 2; ++dy) {
                if (abs(dx) + abs(dy) == 3) {
                    ll nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                        occupied.insert(nx * n + ny);
                    }
                }
            }
        }
    }

    ll total = n * n;
    ll safe = total - occupied.size();
    cout << safe << '\n';

    return 0;
}