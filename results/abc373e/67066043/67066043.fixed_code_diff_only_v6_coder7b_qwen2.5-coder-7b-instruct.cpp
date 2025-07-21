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
    for(int i=0; i<n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the difference between max votes and min votes among top M candidates
    vector<ll> diff(n, 0);
    sort(a.begin(), a.end());
    for(int i=n-M; i<n; i++) {
        diff[a[i]-a[n-M-1]]++;
    }

    // Calculate the prefix sum of differences
    vector<ll> pref(n+1, 0);
    for(int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + diff[i-1];
    }

    // Calculate the minimum additional votes required for each candidate
    vector<ll> ans(n, 0);
    for(int i=0; i<n; i++) {
        ll need = pref[n-M-1] - pref[max(0LL, a[i]-k)];
        ans[i] = need > 0 ? need : -1;
    }

    // Print the results
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}