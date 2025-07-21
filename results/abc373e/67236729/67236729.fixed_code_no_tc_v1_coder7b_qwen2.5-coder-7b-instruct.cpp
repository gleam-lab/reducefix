#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<ll>

// Function to calculate the minimum additional votes needed
vi calc_min_votes(int n, int m, ll k, vi a) {
    vi min_votes(n, -1);
    vi suffix_sum(n + 1, 0);

    // Calculate suffix sum of votes
    for (int i = n - 1; i >= 0; i--)
        suffix_sum[i] = suffix_sum[i + 1] + a[i];

    // Iterate over each candidate
    for (int i = 0; i < n; i++) {
        // Calculate the maximum votes that can be distributed among others
        ll max_votes_others = (suffix_sum[0] - suffix_sum[i + 1]);

        // Check if the current candidate can win with the remaining votes
        if (max_votes_others < (k - suffix_sum[i])) {
            min_votes[i] = 0;
        } else {
            // Binary search to find the minimum additional votes needed
            ll l = 0, r = k - suffix_sum[i];
            while (l <= r) {
                ll mid = l + (r - l) / 2;
                if (mid + max_votes_others < (k - suffix_sum[i])) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            min_votes[i] = l;
        }
    }

    return min_votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vi a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vi res = calc_min_votes(n, m, k, a);

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";

    return 0;
}