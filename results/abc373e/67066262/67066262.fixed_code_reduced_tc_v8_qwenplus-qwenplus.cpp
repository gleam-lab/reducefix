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

    // ord[i] gives the index of the candidate with i-th smallest votes
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
        int i = ord[idx]; // current candidate
        ll curr = a[i];

        ll low = 0, high = k + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // We need to assume worst-case scenario: other candidates get as many votes as possible
            // To guarantee win, we want at least M candidates (including self) with <= (curr + mid) votes
            // So find how many candidates currently have > (curr + mid)
            ll target = curr + mid + 1;
            int pos = lower_bound(all(sorted_a), target) - sorted_a.begin();
            int count_above = n - pos;

            // If candidate i itself is counted in those above, subtract one
            if (a[i] >= target) count_above--;

            if (count_above < m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // Check if it's possible to win with low additional votes
        if (low <= k) {
            res[i] = low;
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << max(0LL, res[i]) << " ";
    }
    cout << "\n";

    return 0;
}