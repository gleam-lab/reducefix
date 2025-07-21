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

    ll total_so_far = accumulate(all(a), 0LL);
    ll remaining = k - total_so_far;

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
        int i = ord[idx]; // original index
        ll ai = a[i];

        ll low = 0, high = remaining + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ll new_ai = ai + mid;

            // Find how many candidates have votes >= new_ai
            // Use binary search on sorted_a
            int pos = lower_bound(sorted_a.begin(), sorted_a.end(), new_ai + 1) - sorted_a.begin();

            // Need to ensure at most M-1 candidates have more than this candidate
            if (n - pos >= m) {
                // Already too many candidates have >= new_ai votes, even with mid additional votes
                low = mid + 1;
                continue;
            }

            // We need to raise the bottom (n - (M - 1)) candidates to new_ai+1
            int target_count = max(0, n - (m - 1));
            int l = lower_bound(sorted_a.begin(), sorted_a.end(), new_ai + 1) - sorted_a.begin();
            int r = upper_bound(sorted_a.begin(), sorted_a.end(), new_ai) - sorted_a.begin();
            int cnt = 0;
            if (l < r && i >= l && i < r) {
                cnt = 0; // do not count current candidate
            }
            l = max(l, n - (m - 1));
            if (l < r) {
                cnt += (r - l) * (new_ai + 1) - (prefix[r] - prefix[l]);
            }
            if (cnt <= remaining - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low > remaining) {
            result[i] = -1;
        } else {
            result[i] = low;
        }
    }

    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';
}