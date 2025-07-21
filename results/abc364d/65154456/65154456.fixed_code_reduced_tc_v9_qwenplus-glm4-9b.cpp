#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005; // We assume the range can be up to 2e8, add 1 for 1-based index

int a[MAX_N]; // We use 1-based indexing, shift all values by 1 million to avoid negative indices

bool check(int mid, int x, int y) {
    // Check if the point A_i at a[min(N - 1, x + mid)] is the k-th closest to B_j at b_j
    int left = max(0, x - mid);
    int right = min((int)1e8, x + mid + 1); // We assume the distance can be up to 2e8
    return (a[right] - a[left]) >= y;
}

void solve() {
    int n, q;
    cin >> n >> q;

    // Read point A coordinates and count occurrences at shifted positions
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x + 100000000]++; // Shift by 1 million to avoid negative indices
    }

    // Compute prefix sums to get the count of points up to each index
    for (int i = 1; i <= MAX_N; i++) {
        a[i] += a[i - 1];
    }

    // For each query, find the k-th closest point to B_j
    while (q--) {
        int x, k;
        cin >> x >> k;
        int l = 1, r = 2e8;
        while (r > l) {
            int mid = l + r >> 1;
            if (check(mid, x + 100000000, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}