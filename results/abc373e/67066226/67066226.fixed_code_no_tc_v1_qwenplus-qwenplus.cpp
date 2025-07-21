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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Calculate remaining votes
    ll total_counted = accumulate(all(a), (ll)0);
    ll remaining = k - total_counted;

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> result(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index of candidate
        ll ai = a[i];

        ll low = 0, high = remaining;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = ai + mid;

            // Find how many candidates have votes strictly greater than target
            // using binary search in the sorted array
            int pos = lower_bound(all(sorted_a), target + 1) - sorted_a.begin();

            // If there are at least M candidates with more votes than this one, it's not enough
            if (n - pos >= m) {
                low = mid + 1;
                continue;
            }

            // Need to make sure even in worst case, we are in top M
            // So we assume that up to (M-1) candidates can have more votes than us
            // We need to ensure our vote count is high enough so that at most (M-1) candidates can be above us

            // Determine how many candidates currently have more than target
            int cnt_above = n - pos;

            // To guarantee election, must ensure that at most (M-1) candidates can have more votes than us
            // So we may need to increase others to try to push them above us, and still survive

            // We want to assume worst-case: as many as possible other candidates get as many votes as possible
            // but still not exceed making us have less than M higher than us

            // We will protect our candidate and assume other candidates get as many votes as possible,
            // without exceeding M-1 being strictly greater than us.

            // The idea:
            // We can allow at most (M-1) candidates to have > target votes
            // So find top (M) candidates excluding current one
            // and make sure that we can raise our candidate to beat the (M)th strongest candidate

            // Let's find how much we need to increase to surpass the (n-m+1)-th highest vote

            // Position in sorted_a where we are located
            int self_pos = lower_bound(all(sorted_a), ai) - sorted_a.begin();
            if (self_pos < n && sorted_a[self_pos] == ai) {
                // skip ourselves
                pos = lower_bound(all(sorted_a), target + 1) - sorted_a.begin();
            }

            // Total needed to bring this candidate to target and ensure win
            // We need to cap number of candidates > target to < M

            // Try to allow only M-1 candidates to be above us
            // Consider the (n-M+1)th smallest value in the sorted list
            // We must be >= that value to be in top M

            ll threshold = sorted_a[n - m]; // This is the minimum value such that only M-1 can be larger
            if (ai + mid > threshold) {
                // Already good
                answer = mid;
                high = mid - 1;
            } else {
                // Need to increase further
                low = mid + 1;
            }
        }

        result[i] = (answer != -1 && answer <= remaining) ? answer : -1;
        if (result[i] == -1 || result[i] > remaining) {
            result[i] = -1;
        } else {
            result[i] = max(result[i], 0LL); // cannot be negative
        }
    }

    for (auto x : result) cout << x << " ";
    cout << "\n";
}