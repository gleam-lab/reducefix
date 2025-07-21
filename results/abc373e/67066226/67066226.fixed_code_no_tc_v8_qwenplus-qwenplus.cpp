#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // ord[i] is the index of the candidate with the i-th smallest current votes
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return a[x] < a[y]; });
    
    vector<ll> sorted_a = a;
    sort(all(sorted_a));

    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_a[i];
    }

    vector<ll> res(n, -1);

    for (int idx = 0; idx < n; ++idx) {
        int i = ord[idx]; // Current candidate in sorted order
        ll ai = sorted_a[idx];

        ll low = 0, high = k;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = ai + mid;

            // Binary search to find how many candidates have votes > target
            ll pos = lower_bound(sorted_a.begin(), sorted_a.end(), target + 1) - sorted_a.begin();
            
            // We need at most M-1 candidates to have more votes than current candidate
            // So we can allow up to (M-1) candidates to have votes > target
            if (n - pos >= m) {
                // Already too many people above target, no need to add more
                answer = 0;
                low = mid + 1;
                continue;
            }

            // Need to cap the number of people that can be above this candidate to M-1
            ll needed = max(0LL, (n - (m - 1)) - idx);
            ll left = max(0LL, needed - 1);
            ll required = (target + 1) * (idx - left) - (prefix[idx + 1] - prefix[left]);

            if (required <= k) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        res[i] = (answer == -1 ? -1 : answer);
    }

    for (ll val : res)
        cout << max(0LL, val) << " ";
}