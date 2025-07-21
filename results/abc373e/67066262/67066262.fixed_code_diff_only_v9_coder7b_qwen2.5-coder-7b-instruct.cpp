#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i], k -= a[i];

    vector<pair<ll, int>> sorted_a;
    for (int i = 0; i < n; ++i)
        sorted_a.emplace_back(a[i], i);

    sort(sorted_a.rbegin(), sorted_a.rend());

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + sorted_a[i].first;

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll total_votes_needed = 0;
        for (int j = 0; j < n - m; ++j)
            total_votes_needed += sorted_a[j].first + 1;
        
        ll target = (k - total_votes_needed) / (n - m);
        
        if (sorted_a[i].first <= target) {
            ans[sorted_a[i].second] = max(0LL, target - sorted_a[i].first + 1);
        } else {
            ans[sorted_a[i].second] = 0;
        }
    }

    for (ll x : ans)
        cout << x << " ";

    return 0;
}