#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> ans(n, -1);

    for(int i = 0; i < n; ++i) {
        ll x = 0;
        for(int j = i + 1; j < n; ++j) {
            if(a[j] > a[i]) {
                x = max(x, a[j] - a[i] + 1);
            }
        }
        if(i >= n - m) {
            x = max(x, k / (n - m));
        } else {
            x = max(x, (k - (a[n-1] - a[i])) / (m - 1));
        }
        ans[ord[i]] = x;
    }

    for(ll x : ans) cout << x << " ";
    return 0;
}