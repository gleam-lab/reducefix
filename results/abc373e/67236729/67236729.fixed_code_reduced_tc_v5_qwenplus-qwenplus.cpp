#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> A(n);
    for (auto &x : A) {
        cin >> x;
        k -= x;
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }

    vector<ll> result(n);

    for (int i = 0; i < n; ++i) {
        ll low = 0, high = k, ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = A[i] + mid;

            // Find how many candidates have strictly more than target
            // We use upper_bound on reversed array to simulate greater-than count
            int idx = lower_bound(sorted_A.begin(), sorted_A.end(), target + 1) - sorted_A.begin();
            int higher_count = n - idx;

            if (higher_count < m) {
                ans = mid;
                high = mid - 1;
            } else {
                // Not enough votes added yet
                low = mid + 1;
            }
        }

        result[i] = (k >= 0 && (ans == -1 ? -1 : ans));
    }

    for (auto &x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}