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

    // Find the total votes needed for the top M candidates
    sort(a.rbegin(), a.rend());
    ll total_votes_needed = 0;
    for (int i = 0; i < m; ++i) {
        total_votes_needed += a[i];
    }

    // Calculate the maximum votes other candidates can get
    ll max_other_votes = k - (total_votes_needed - a[m-1]);

    // Determine the minimum votes needed for each candidate
    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] > max_other_votes) {
            ans[i] = 0;
        } else {
            ans[i] = max_other_votes - a[i] + 1;
        }
    }

    // Ensure no candidate gets more votes than necessary
    for (int i = 0; i < n; ++i) {
        if (ans[i] != -1 && a[i] + ans[i] <= max_other_votes) {
            ans[i] = -1;
        }
    }

    // Output the results
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}