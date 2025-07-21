#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, m; cin >> n >> m;
    vector<ll> row(n + 1), col(n + 1), diag1(2 * n + 1), diag2(2 * n + 1);

    for(ll i = 0; i < m; ++i) {
        ll r, c; cin >> r >> c;
        --r; --c; // Convert to zero-based index
        row[r] = col[c] = diag1[r - c + n] = diag2[r + c] = 1;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(row[i] == 0 && col[j] == 0 && diag1[i - j + n] == 0 && diag2[i + j] == 0) {
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}