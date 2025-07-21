#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort indices based on the number of votes in descending order
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return a[i] > a[j]; });

    // Calculate prefix sums of sorted vote counts
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[idx[i]];
    }

    // Initialize answer array
    vector<ll> ans(n, -1);

    for(int i = 0; i < n; ++i) {
        ll target = a[idx[i]] + 1; // Candidate needs at least one more vote than the next highest
        int j = i + 1;
        
        // Binary search to find the smallest X such that candidate can win
        ll left = 0, right = k + 1;
        while(left < right) {
            ll mid = (left + right) / 2;
            
            // Count the number of candidates who can surpass the current candidate with mid additional votes
            ll excess_votes = 0;
            for(; j < n && a[idx[j]] + mid > target; ++j) {
                excess_votes += (a[idx[j]] + mid) - target;
            }
            
            // Check if remaining votes are sufficient to cover the excess votes
            if(excess_votes <= mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // If no valid X found, set answer to -1
        if(left == k + 1) {
            ans[idx[i]] = -1;
        } else {
            ans[idx[i]] = left;
        }
    }

    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}