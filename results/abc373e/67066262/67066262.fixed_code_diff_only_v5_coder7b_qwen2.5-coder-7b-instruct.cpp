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

    // Calculate the maximum number of votes any candidate can get
    ll max_votes = *max_element(a.begin(), a.end());

    // Initialize answer array with -1
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for(int i = 0; i < n; i++) {
        // If a candidate already has more votes than m-1 others, they win
        if(i >= n - m) {
            ans[i] = 0;
            continue;
        }

        // Binary search for the minimum number of additional votes needed
        ll left = 0, right = k;
        while(left <= right) {
            ll mid = left + (right - left) / 2;
            // Calculate the total votes after giving mid additional votes to candidate i
            ll total_votes = a[i] + mid;
            // Count how many candidates would have more votes than total_votes
            ll count = 0;
            for(int j = 0; j < n; j++) {
                if(j != i && a[j] > total_votes) {
                    count++;
                }
            }
            // If count is less than m, candidate i wins
            if(count < m) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Update the answer array
        ans[i] = left;
    }

    // Print the results
    for(ll x : ans) cout << x << " ";

    return 0;
}