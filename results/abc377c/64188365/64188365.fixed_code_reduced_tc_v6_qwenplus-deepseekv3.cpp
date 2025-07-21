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
        a--; b--; // converting to 0-based index
        forbidden.emplace(a, b);
        
        // Check all 8 possible knight moves
        const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        rep(k, 8) {
            ll nx = a + dx[k];
            ll ny = b + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                forbidden.emplace(nx, ny);
            }
        }
    }
    cout << n * n - forbidden.size() << endl;
}