#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort the array in descending order
    sort(a.rbegin(), a.rend());

    // Calculate the prefix sum array
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Initialize the answer array
    vector<ll> ans(n, -1);

    // Iterate over each candidate
    for (int i = 0; i < n; ++i) {
        // Calculate the required votes for candidate i to win
        ll required_votes = k + pref[m];

        // Check if candidate i can win with the remaining votes
        if (a[i] > required_votes) {
            ans[i] = 0;
        } else {
            // Binary search for the minimum number of additional votes needed
            int left = 0, right = k;
            while (left < right) {
                int mid = left + (right - left) / 2;
                ll total_votes = a[i] + mid + pref[min(m, i + 1)];
                if (total_votes > required_votes) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = left;
        }
    }

    // Print the result
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}