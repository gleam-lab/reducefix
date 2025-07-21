#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

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

    // Sort the votes in descending order
    sort(all(a), greater<ll>());

    // Calculate prefix sums
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    vector<ll> ans(n, -1);

    for(int i = 0; i < n; ++i) {
        ll need = 0;
        if(i < n - m) {
            need = max((ll)0, pref[n] - pref[i + 1] - (m - (i >= n - m ? 1 : 0)) * (a[i] + need + 1) - (n - i - 1));
        } else {
            need = max((ll)0, pref[n] - pref[i + 1] - (a[i] + need + 1));
        }

        if(need <= k) {
            ans[i] = need;
        }
    }

    for(auto i : ans) cout << i << ' ';
    return 0;
}