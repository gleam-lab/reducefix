#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        if(a[i] + k < m) continue;

        ll l = 0, r = k + 1;
        while(r - l > 1) {
            ll mid = (l + r) / 2;
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(j != i && a[j] + mid > a[i]) {
                    ++cnt;
                }
            }
            if(cnt < m) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans[i] = l;
    }

    for(ll x : ans) {
        cout << x << " ";
    }
    return 0;
}