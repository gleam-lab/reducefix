#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MOD 1e9 + 7
#define INF INT_MAX

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll ans = INF;

    for(int i = 0; i <= k; i++) {
        ans = min(ans, a[k - i] - a[i]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}