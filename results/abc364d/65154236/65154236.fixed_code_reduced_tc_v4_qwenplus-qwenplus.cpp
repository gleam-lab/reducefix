#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use binary search on distance
    ll left = 0;
    ll right = 2e8; // max possible distance is up to 2e8 (from -1e8 to 1e8)

    while (left < right) {
        ll mid = (left + right) / 2;
        // Count how many elements in a are within distance <= mid from b
        ll cnt = upper_bound(a, a + n, b + mid) - lower_bound(a, a + n, b - mid);
        if (cnt < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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