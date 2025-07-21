#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N];

int find_kth_distance(int n, int x, int k) {
    int left = 0;
    int right = 2e8; // Maximum possible distance considering the constraints
    int answer = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;

        // Use lower_bound and upper_bound to find the range [x - mid, x + mid]
        int lower = x - mid;
        int upper = x + mid;
        int l = lower_bound(a, a + n, lower) - a;
        int r = upper_bound(a, a + n, upper) - a;

        count = r - l;

        if (count >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
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
        int x, k;
        cin >> x >> k;
        cout << find_kth_distance(n, x, k) << '\n';
    }

    return 0;
}