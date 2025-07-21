#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN];

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

    while (Q--) {
        long long b, k;
        cin >> b >> k;

        // Binary search on answer: smallest distance d such that there are at least k points within distance <= d from b
        long long low = 0;
        long long high = 2e8;
        long long answer = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long left = b - mid;
            long long right = b + mid;

            // Use lower_bound and upper_bound to count how many points are in [left, right]
            int l = lower_bound(a, a + N, left) - a;
            int r = upper_bound(a, a + N, right) - a;
            int count = r - l;

            if (count >= k) {
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