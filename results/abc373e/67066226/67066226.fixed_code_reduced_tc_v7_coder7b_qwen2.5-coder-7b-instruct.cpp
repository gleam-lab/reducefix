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
    sort(ord.begin(), ord.end(), [&](int i, int j){ return a[i] > a[j]; });

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(i >= m) break;
        ll x = 0;
        for(int j = 0; j < n; ++j) {
            if(j != i && a[j] > a[i]) {
                x = max(x, a[j] - a[i] + 1);
            }
        }
        if(k >= x) {
            ans[i] = x;
            k -= x;
        } else {
            ans[i] = -1;
        }
    }

    for(ll v : ans) cout << v << " ";
    cout << endl;

    return 0;
}