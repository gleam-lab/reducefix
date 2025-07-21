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
    ll sum_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    ll remaining = k - sum_a;
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = a[i] + mid;
            // Find the number of candidates with votes > new_votes
            auto it = upper_bound(all(b), new_votes);
            int count_greater = b.end() - it;
            // If the candidate themselves is among those > new_votes, adjust
            if (a[i] + mid > new_votes) {
                // This might not be necessary as mid is added to a[i]
            }
            // Now, count_greater should be <= m - 1
            if (count_greater <= m - 1) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1) {
            // Check if the remaining votes are sufficient to push enough candidates down
            // Calculate the required votes to ensure that at most m-1 candidates are above new_votes
            ll new_votes = a[i] + best;
            auto it = upper_bound(all(b), new_votes);
            int count_greater = b.end() - it;
            if (count_greater > m - 1) {
                best = -1;
            } else {
                // Check if remaining votes can cover the best
                if (best <= remaining) {
                    ans[i] = best;
                } else {
                    ans[i] = -1;
                }
            }
        }
        // Also, if candidate is already in the top M
        ll current_votes = a[i];
        auto it = upper_bound(all(b), current_votes);
        int current_count = b.end() - it;
        if (current_count < m) {
            ans[i] = 0;
        }
    }
    for (auto num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
    return 0;
}