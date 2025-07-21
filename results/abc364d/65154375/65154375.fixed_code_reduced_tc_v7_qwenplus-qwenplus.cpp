#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search helper to find k-th smallest distance
ll query(ll b, ll k, int n) {
    // Create a sorted copy of a[] for each query (incorrect in original code)
    // We will use binary search on the answer: distance d
    // Check how many points are within distance d from b

    ll left = 0, right = 2e8; // Max possible distance is 2*1e8
    ll ans = -1;

    while (left <= right) {
        ll mid = (left + right) / 2;
        // Find range [b-mid, b+mid]
        ll l = lower_bound(a, a + n, b - mid) - a;
        ll r = upper_bound(a, a + n, b + mid) - a;
        ll count = r - l;

        if (count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);

    for (int i = 0; i < Q; ++i) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k, N) << "\n";
    }

    return 0;
}