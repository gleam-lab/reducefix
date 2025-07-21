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

    // Sort the votes in descending order
    vector<pair<ll, int>> sorted_a;
    for(int i = 0; i < n; ++i) {
        sorted_a.push_back({a[i], i});
    }
    sort(sorted_a.rbegin(), sorted_a.rend());

    // Calculate the prefix sum of votes
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + sorted_a[i].first;
    }

    // Determine the minimum number of additional votes needed
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        ll votes_needed = 0;
        if(i + 1 < m) {
            votes_needed = max(0LL, (sorted_a[i + 1].first * (m - 1)) - (pref[n] - pref[i + 1]));
        } else {
            votes_needed = max(0LL, (sorted_a[m].first * (n - m)) - (pref[n] - pref[m]));
        }
        ans[sorted_a[i].second] = votes_needed;
    }

    // Output the results
    for(auto i : ans) cout << i << ' ';
    return 0;
}