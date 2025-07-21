#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n), b(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i) cin >> b[i] >> a[i];

    // Combine all points into one sorted list
    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        ll bj = b[i];
        int k = a[i];

        // Binary search to find the first element >= bj
        auto it = lower_bound(a.begin(), a.end(), bj);

        // Count the number of elements <= bj
        int cnt_le_bj = it - a.begin();

        // If there are fewer than k elements <= bj, we need to look at the next segment
        if (cnt_le_bj < k) {
            k -= cnt_le_bj;
            it = upper_bound(it, a.end(), bj);
        }

        // Now it points to the first element > bj
        // We need the (k-1)-th smallest element in the range [it-k, it-1]
        if (it - k >= a.begin()) {
            cout << *(it - k) - bj << '\n';
        } else {
            cout << 0 << '\n'; // This case shouldn't happen with valid inputs
        }
    }

    return 0;
}