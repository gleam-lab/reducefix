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

    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; idx++) {
        int i = ord[idx];
        ll ai = a[i];

        // Binary search on additional votes needed
        ll low = 0, high = k;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = ai + mid;

            // We need at least (N - M + 1) candidates with >= total votes to ensure i is in top M
            // Find how many candidates already have >= total
            int cnt = n - (lower_bound(all(sorted_a), total) - sorted_a.begin());

            // If current candidate gets mid more votes, we must ensure that at most M-1 candidates can beat them
            // So number of candidates > total must be < M => number of candidates >= total is <= M
            // So we need to possibly increase some other candidates to reach total

            // Remaining candidates that can be pushed to total
            ll need = max(0, (M - (cnt - (ai + mid == total ? 1 : 0)))); // How many more do we need to bring to >= total

            // Total votes required to raise "need" smallest candidates below current to total
            ll l = 0, r = idx;
            ll pos = upper_bound(all(sorted_a), ai + mid) - sorted_a.begin();
            if (pos <= idx) {
                pos = idx;
            }
            ll sum = 0;
            if (pos < n) {
                sum = (ai + mid) * (n - pos);
                ll actual_sum = (prefix[n] - prefix[pos]);
                ll extra = sum - actual_sum;
                if (extra < 0) extra = 0;
                if (mid + extra <= k) {
                    answer = mid;
                    high = mid - 1;
                    continue;
                }
            }

            low = mid + 1;
        }

        res[i] = answer;
    }

    for (auto x : res) cout << x << " ";
    cout << "\n";
}