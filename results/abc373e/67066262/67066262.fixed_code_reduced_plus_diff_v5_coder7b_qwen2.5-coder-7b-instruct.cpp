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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the vote counts in descending order
    sort(a.rbegin(), a.rend());

    // Calculate the prefix sum array for quick access
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Initialize the result array with -1
    vector<ll> ans(n, -1);

    // Iterate through each candidate
    for (int i = 0; i < n; ++i) {
        ll x = 0;
        int remaining_candidates = n - i;
        
        // Calculate the minimum number of additional votes needed
        if (remaining_candidates <= m) {
            x = 0;
        } else {
            // Binary search to find the minimum additional votes needed
            ll l = 0, r = k + 1;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                int lid = n - m - (i >= n - m ? 1 : 0);
                ll cnt = 0;
                
                if (lid <= i && i < lid + mid) {
                    cnt++;
                } else {
                    cnt += mid;
                }
                
                if (cnt > k) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            x = r;
        }

        // Check if the candidate can win with the calculated additional votes
        if (a[i] + x >= pref[n] - pref[i + 1]) {
            ans[i] = 0;
        } else {
            ans[i] = x;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}