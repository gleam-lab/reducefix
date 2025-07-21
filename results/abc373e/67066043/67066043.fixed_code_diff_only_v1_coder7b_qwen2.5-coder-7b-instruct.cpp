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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll needed_votes = 0;
        for(int j = i + 1; j < min(i + m, n); j++) {
            needed_votes += max(0LL, a[j] - a[i] + 1);
        }
        if(k >= needed_votes) {
            ans[ord[i]] = 0;
        } else {
            ans[ord[i]] = needed_votes - k;
        }
    }

    for(auto i : ans) cout << i << ' ';
    return 0;
}