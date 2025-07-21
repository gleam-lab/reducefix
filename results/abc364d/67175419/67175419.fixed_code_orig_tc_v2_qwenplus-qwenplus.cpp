#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN];
int n, q;

// Binary search to find the smallest distance d such that there are at least k points within distance d of b
int solve(int b, int k) {
    int left = 0;
    int right = 2e8; // max possible distance is 2*1e8 (from -1e8 to 1e8)
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        // Use lower_bound and upper_bound to count how many points are in [b - mid, b + mid]
        int low = lower_bound(a, a + n, b - mid) - a;
        int high = upper_bound(a, a + n, b + mid) - a;
        int count = high - low;

        if (count >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        cout << solve(b, k) << "\n";
    }

    return 0;
}