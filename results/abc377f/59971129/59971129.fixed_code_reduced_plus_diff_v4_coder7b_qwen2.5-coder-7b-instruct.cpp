#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MAXN = 1e9 + 7;

vector<ll> rows, cols, diag1, diag2;

void update(vector<ll>& vec, ll idx, bool add) {
    if (add)
        vec[idx]++;
    else
        vec[idx]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<bool> occupied(n * n + 1, false);
    
    for (ll i = 0; i < m; ++i) {
        ll r, c;
        cin >> r >> c;
        occupied[(r - 1) * n + c] = true;
        update(rows, r, true);
        update(cols, c, true);
        update(diag1, r + c, true);
        update(diag2, r - c + n, true);
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (!occupied[(i - 1) * n + j] && 
                !rows[i] && !cols[j] && !diag1[i + j] && !diag2[i - j + n]) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}