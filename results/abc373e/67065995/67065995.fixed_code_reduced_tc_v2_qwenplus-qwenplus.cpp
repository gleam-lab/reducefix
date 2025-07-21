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
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // original index
        ll low = 0, high = k + 1;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = a[i] + mid;

            // We need to ensure that at most M-1 candidates have more votes than this candidate

            // Binary search to find how many candidates can have strictly more than new_vote
            int left = 0, right = n;
            while (left < right) {
                int m = (left + right) / 2;
                if (sorted_a[m] > new_vote)
                    right = m;
                else
                    left = m + 1;
            }
            int cnt = left;

            if (cnt < m) {
                // Not enough candidates to block us, we are in top M
                ans = mid;
                high = mid - 1;
            } else {
                // Need to increase our votes
                low = mid + 1;
            }
        }

        res[i] = (ans > k) ? -1 : ans;
    }

    for (auto x : res) {
        cout << max(0LL, x) << ' ';
    }
}