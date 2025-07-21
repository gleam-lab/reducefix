#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
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
    
    // Sort the votes and indices to determine the order
    vector<pair<ll, int>> indexed_a(n);
    for(int i = 0; i < n; ++i) {
        indexed_a[i] = {a[i], i};
    }
    sort(all(indexed_a));
    vector<ll> sorted_a(n);
    vector<int> ord(n);
    for(int i = 0; i < n; ++i) {
        sorted_a[i] = indexed_a[i].first;
        ord[i] = indexed_a[i].second;
    }
    
    // Calculate prefix sum of sorted array
    vector<ll> pref(n);
    pref[0] = sorted_a[0];
    for(int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + sorted_a[i];
    }
    
    // Calculate the minimum votes needed for each candidate to guarantee victory
    vector<ll> ans(n);
    for(int i = 0; i < n; ++i) {
        ll required = 0;
        // Calculate the votes needed to beat the next M-1 candidates
        if (i + m < n) {
            required = sorted_a[i] + (pref[n - m] - pref[i + m]);
        } else {
            required = sorted_a[i] + (pref[n - 1] - pref[i]);
        }
        
        // Calculate required votes from remaining ballots
        if (k < required) {
            ans[ord[i]] = -1;
        } else {
            required = max(0LL, required - k);
            ans[ord[i]] = required;
        }
    }
    
    for(ll i : ans) cout << i << ' ';
    return 0;
}