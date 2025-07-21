#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_input(false); cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the array to get the relative order of votes
    vector<pair<ll, int>> b(n);
    for(int i = 0; i < n; ++i) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    // Initialize prefix sum array
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) pref[i + 1] = pref[i] + b[i].first;

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int idx = b[i].second;
        ll needed = 0;

        // Calculate the number of candidates with more votes than candidate i
        int cnt = 0;
        for(int j = i + 1; j < n; ++j) {
            if(b[j].first > b[idx].first) ++cnt;
        }

        if(cnt < m) {
            // Binary search to find the minimum additional votes needed
            ll left = 0, right = k;
            while(left < right) {
                ll mid = left + (right - left) / 2;
                ll sum = pref[n] - pref[i + 1] + (n - i - 1) * mid;
                if(sum >= (m - cnt) * b[idx].first) right = mid;
                else left = mid + 1;
            }
            needed = left;
        } else {
            // Candidate i can't win regardless of additional votes
            needed = -1;
        }

        ans[idx] = needed;
    }

    // Output the results
    for(int i = 0; i < n; ++i) cout << ans[i] << " ";
    return 0;
}