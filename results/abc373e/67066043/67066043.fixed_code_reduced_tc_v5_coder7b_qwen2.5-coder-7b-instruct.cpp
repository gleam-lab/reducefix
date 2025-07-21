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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates by their current vote counts
    vector<pair<ll, int>> candidates(n);
    for (int i = 0; i < n; ++i) {
        candidates[i] = {a[i], i};
    }
    sort(candidates.begin(), candidates.end());

    // Calculate the prefix sum of sorted vote counts
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + candidates[i].first;
    }

    // Determine the minimum votes needed for each candidate
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll votes_needed = -1;
        
        // Binary search to find the minimum votes needed
        ll left = 0, right = k + 1;
        while (left < right) {
            ll mid = (left + right) / 2;
            int rank = upper_bound(candidates.begin(), candidates.end(), make_pair(mid + candidates[i].first, -1)) - candidates.begin();
            
            if (rank > n - m) {
                right = mid;
            } else {
                left = mid + 1;
                votes_needed = mid;
            }
        }
        
        // Adjust votes_needed if it exceeds the total remaining votes
        if (votes_needed != -1) {
            votes_needed = min(votes_needed, k);
        }
        
        ans[candidates[i].second] = votes_needed;
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}