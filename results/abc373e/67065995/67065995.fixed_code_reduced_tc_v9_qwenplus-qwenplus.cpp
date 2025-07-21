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

    // Total remaining votes
    ll total_remaining = k;
    for (ll ai : a) {
        total_remaining -= ai;
    }

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
        int i = ord[idx]; // original index
        ll current = a[i];

        ll low = 0, high = total_remaining + 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = current + mid;

            // Find how many candidates have score >= new_score
            int left = upper_bound(sorted_a.begin(), sorted_a.end(), new_score - 1) - sorted_a.begin();
            int right = upper_bound(sorted_a.begin(), sorted_a.end(), new_score) - sorted_a.begin();

            // We need to ensure that fewer than M candidates have more than new_score
            // That means at most M-1 candidates can have > new_score
            // So we need at least (n - (M - 1)) candidates with >= new_score
            int needed = n - (m - 1);
            if (n - right >= needed) {
                // Already enough
                res[i] = mid;
                high = mid - 1;
            } else {
                // Need to increase scores of some from right to reach new_score
                int to_increase = needed - (n - right);
                ll extra_needed = to_increase * new_score - (prefix[right + to_increase] - prefix[right]);
                if (extra_needed <= total_remaining - mid) {
                    res[i] = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
    }

    for (ll val : res) {
        cout << val << " ";
    }
    cout << "\n";
}