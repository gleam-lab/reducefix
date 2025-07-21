#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    set<pair<ll, ll>> forbidden;
    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        forbidden.insert({a, b});
        // Check all 8 possible knight moves
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        rep(dir, 8) {
            ll x = a + dx[dir];
            ll y = b + dy[dir];
            if (x >= 0 && x < n && y >= 0 && y < n) {
                forbidden.insert({x, y});
            }
        }
    }
    cout << n * n - forbidden.size() << endl;
}