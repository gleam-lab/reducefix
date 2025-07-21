#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

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

        // Binary search bounds
        long long low = 0;
        long long high = 2e8;

        auto count_kth = [&](long long mid) {
            int left = lower_bound(a, a + n, b - mid) - a;
            int right = upper_bound(a, a + n, b + mid) - a;
            return right - left >= k;
        };

        long long answer = high;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (count_kth(mid)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}