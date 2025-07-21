#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }
    sort(a.begin(), a.end(), greater<ll>()); // Sort votes in descending order

    vector<ll> b(a); // Copy votes for further calculations
    vector<ll> pref(n + 1, 0); // Prefix sum array

    // Compute prefix sums of b for quick range sum calculations
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    vector<ll> ans(n, -1); // Result for each candidate
    vector<int> ord(n); // Original indices to restore order

    // Restore original indices
    for (int i = 0; i < n; i++) {
        ord[i] = i;
    }

    // Sort candidates by number of votes they have
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return a[i] > a[j];
    });

    // Evaluate each candidate
    for (int i = 0; i < n; i++) {
        int pos = ord[i]; // Current candidate position
        ll votes_needed = 0; // Additional votes needed
        ll votes_without_current = pref[i] - b[i]; // Total votes excluding current candidate

        // Check if the current candidate can still win
        if (a[i] + votes_needed < m * (b[i] - votes_needed)) {
            votes_needed = (m * b[i] - a[i]) / (m + 1);
        }

        // Check if the additional votes exceed the remaining votes
        if ( votes_needed + votes_without_current >= k) {
            votes_needed = max(0LL, k - votes_without_current);
        }

        // Update the answer for the current candidate
        if (a[i] + votes_needed < m * (b[i] - votes_needed)) {
            ans[pos] = votes_needed;
        } else {
            ans[pos] = -1;
        }
    }

    // Output the results
    for (ll v : ans) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}