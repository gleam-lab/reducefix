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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll total_so_far = accumulate(all(a), 0LL);
    ll remaining = k - total_so_far;

    // For each candidate, determine how many more votes they need to guarantee election
    vector<ll> res(n, -1);

    // We'll process candidates in order of current vote counts
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    // Prefix sum of sorted_a
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx]; // original index of candidate
        ll ai = a[i];

        // Binary search on minimum additional votes needed
        ll low = 0, high = remaining + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll new_ai = ai + mid;

            // Find number of candidates with votes > new_ai
            // We want this number < M

            // Number of candidates that can have >= new_ai+1 votes
            // We want to ensure at most M-1 candidates have > new_ai votes
            // So at most M-1 candidates can have >= new_ai+1 votes

            // Use binary search on sorted_a to find how many candidates can be above us
            int pos = upper_bound(all(sorted_a), new_ai) - sorted_a.begin();

            // We need to make sure that even if the remaining votes are distributed to maximize other candidates,
            // at most M-1 candidates have more than new_ai votes.

            // Total votes needed to raise the bottom (n-M+1) candidates to new_ai+1
            // But we're candidate i, so if i is among these, we don't need to raise our own votes again
            int l = n - m;
            if (pos > l) {
                ll needed = (new_ai + 1) * (pos - l) - (prefix[pos] - prefix[l]);
                if (i >= l && i < pos) {
                    needed -= mid; // already counted our mid additional votes
                }
                if (needed <= remaining - mid) {
                    // It's possible to have more than M-1 candidates with > new_ai votes
                    high = mid;
                } else {
                    low = mid + 1;
                }
            } else {
                // We're guaranteed to be in top M
                high = mid;
            }
        }

        if (low <= remaining)
            res[i] = low;
        else
            res[i] = -1;
    }

    for (auto x : res)
        cout << x << " ";
}