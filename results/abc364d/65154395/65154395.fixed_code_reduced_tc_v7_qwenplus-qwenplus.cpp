#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will find the smallest radius r such that there are at least k points within distance r of b
    
    // Define binary search bounds
    ll left = 0;
    ll right = 2e8;  // max possible distance between -1e8 and 1e8

    while (left < right) {
        ll mid = (left + right) / 2;
        // Find number of elements in a[] with |a[i] - b| <= mid
        ll left_pos = b - mid;
        ll right_pos = b + mid;

        // Use binary search to count how many elements fall into [left_pos, right_pos]
        int l = lower_bound(a, a + n, left_pos) - a;
        int r = upper_bound(a, a + n, right_pos) - a;
        int count = r - l;

        if (count >= k)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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