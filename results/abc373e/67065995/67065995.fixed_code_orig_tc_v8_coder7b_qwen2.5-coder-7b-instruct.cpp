#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

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

    // Sort the array to facilitate calculation of required votes
    sort(all(a));

    // Calculate prefix sums for quick access to cumulative vote counts
    vector<ll> pref(n + 1);
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        // Binary search to find the smallest number of additional votes needed
        ll left = 0, right = k + 1;
        while(left < right) {
            ll mid = (left + right) / 2;
            // Find the index where mid + a[i] would rank among candidates
            auto it = upper_bound(all(a), a[i] + mid);
            int idx = it - a.begin();
            // Number of candidates with higher scores than candidate i
            int cnt_higher = n - idx;

            // Check if candidate i can still win even after giving away mid votes
            if(idx >= m || cnt_higher < m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // The minimum number of votes needed for candidate i to win
        if(left <= k) {
            ans[i] = left;
        }
    }

    for(ll x : ans) cout << x << " ";
    return 0;
}