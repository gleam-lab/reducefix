#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

// Binary search for k-th smallest distance
int solve(int x, int k) {
    int n = ::n;
    // Binary search on distance d
    int low = 0, high = 2e8, ans = 0;
    while (low <= high) {
        int mid = (1LL * low + high) / 2;
        // Count number of elements in [x - mid, x + mid]
        int left = lower_bound(a, a + n, x - mid) - a;
        int right = upper_bound(a, a + n, x + mid) - a;
        if (right - left >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
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
        int b, k;
        cin >> b >> k;
        cout << abs(b - a[solve(b, k)]) << "\n";
    }

    return 0;
}