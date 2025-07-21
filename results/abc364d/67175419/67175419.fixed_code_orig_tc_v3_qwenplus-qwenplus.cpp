#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
int a[MAXN];
int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        long long b, k;
        cin >> b >> k;
        // Binary search the smallest distance d such that there are at least k points within distance d of b
        long long low = 0, high = 2e8;
        long long answer = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            // Find the first A_i >= (b - mid)
            int* left = lower_bound(a, a + n, b - mid);
            // Find the first A_i > (b + mid)
            int* right = upper_bound(a, a + n, b + mid);
            int count = right - left;
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}