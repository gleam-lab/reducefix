#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_castio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<ll> res(n, -1);
    for(int i = 0; i < n; ++i) {
        ll need = (m - 1) * a[i] - pref[i] + 1;
        if(need <= k) {
            res[i] = need;
        }
    }

    for(int i = 0; i < n; ++i) {
        if(res[i] != -1) {
            for(int j = i + 1; j < n; ++j) {
                if(res[j] == -1 || res[j] > res[i]) {
                    res[j] = res[i];
                } else {
                    break;
                }
            }
        }
    }

    for(int i = n - 2; i >= 0; --i) {
        if(res[i] == -1) {
            res[i] = res[i + 1];
        }
    }

    for(ll x : res) {
        cout << x << " ";
    }
    return 0;
}