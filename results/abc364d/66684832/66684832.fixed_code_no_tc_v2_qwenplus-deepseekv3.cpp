#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define int long long

const int N = 1e5 + 5;

int a[N];

int find_kth_distance(int n, int b, int k) {
    int left = 0;
    int right = 2e14; // Sufficiently large to cover all possible distances

    while (left < right) {
        int mid = (left + right) / 2;
        // Count the number of elements <= b + mid and >= b - mid
        int lower = lower_bound(a, a + n, b - mid) - a;
        int upper = upper_bound(a, a + n, b + mid) - a;
        int count = upper - lower;

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        int left = 0;
        int right = 2e14;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            int lower = lower_bound(a, a + n, b - mid) - a;
            int upper = upper_bound(a, a + n, b + mid) - a;
            int count = upper - lower;

            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << '\n';
    }

    return 0;
}