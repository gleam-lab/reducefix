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

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> suffix_sum(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suffix_sum[i] = suffix_sum[i + 1] + sorted_a[i];
    }

    vector<ll> res(n);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index
        ll ai = a[i];

        ll low = 0;
        ll high = k;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // We need to ensure that at most M-1 candidates have strictly more votes than ai + mid
            // So we assume the worst-case scenario: remaining votes distributed to maximize other candidates,
            // but without exceeding ai + mid.

            // The number of candidates with higher votes before:
            // Since sorted_a is sorted ascending, we use binary search
            ll threshold = ai + mid;

            // Number of candidates with votes > threshold
            // Find first index in sorted_a where value > threshold
            int cnt_more = n - (upper_bound(all(sorted_a), threshold) - sorted_a.begin());

            // We want cnt_more < M
            if (cnt_more < m) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = (answer == -1 ? -1 : answer);
    }

    for (auto x : res) {
        cout << (x == -1 && K >= 0 ? 0 : x) << ' ';
    }
    cout << '\n';
}