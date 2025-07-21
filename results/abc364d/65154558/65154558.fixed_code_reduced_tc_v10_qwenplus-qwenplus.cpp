#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use two pointers to maintain a sliding window
    ll left = 0, right = 0, cnt = 0;
    ll res = 0;

    // Sort the array
    sort(a, a + n);

    // Sliding window to find the k-th closest
    for (int i = 0; i < n; ++i) {
        while (right < n && abs(a[right] - b) <= abs(a[i] - b)) {
            ++right;
        }
        cnt += right - i;
        if (cnt >= k) {
            res = abs(a[i] - b);
            break;
        }
    }

    return res;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);  // Sort A once

    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;

        // Use binary search on answer approach
        ll low = 0, high = 2e8, ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;

            // Count how many elements in A have distance <= mid from b
            int l = lower_bound(a, a + N, b - mid) - a;
            int r = upper_bound(a, a + N, b + mid) - a;
            int count = r - l;

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}