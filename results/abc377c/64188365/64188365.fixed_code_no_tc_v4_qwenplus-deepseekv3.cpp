#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> unsafe;
    set<pair<ll, ll>> pieces;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.emplace(a, b);
        unsafe.emplace(a, b);
        // Check all 8 possible moves for each piece
        for (int dx : {-2, -1, 1, 2}) {
            for (int dy : {-2, -1, 1, 2}) {
                if (abs(dx) + abs(dy) == 3) {
                    ll x = a + dx;
                    ll y = b + dy;
                    if (x >= 1 && x <= n && y >= 1 && y <= n) {
                        unsafe.emplace(x, y);
                    }
                }
            }
        }
    }
    cout << n * n - unsafe.size() << endl;
    return 0;
}