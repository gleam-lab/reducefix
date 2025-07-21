#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    // Calculate the prefix sum array for sorted votes
    vector<ll> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = sorted_a[i] + pref[i];
    }

    // Initialize the result array with -1
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; ++i) {
        // If the current candidate has already won, set the answer to 0
        if(i >= n - m) {
            ans[i] = 0;
            continue;
        }

        // Binary search to find the minimum number of additional votes needed
        ll l = 0, r = k + 1;
        while(l < r) {
            ll mid = (l + r) / 2;
            int pos = upper_bound(sorted_a.begin(), sorted_a.end(), sorted_a[i] + mid) - sorted_a.begin();
            ll extra_votes = (pos - (n - m)) * (sorted_a[i] + mid) - pref[pos] + pref[n - m];
            if(extra_votes > k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // Adjust the result based on the binary search outcome
        if(l == k + 1) {
            ans[i] = -1;
        } else {
            ans[i] = l;
        }
    }

    // Output the results
    for(ll x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}