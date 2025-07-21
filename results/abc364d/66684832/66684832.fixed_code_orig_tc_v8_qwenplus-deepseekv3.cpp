#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

const int N = 1e5 + 9;

int n, q;
int a[N];

int count_within(int x, int d) {
    int left = lower_bound(a, a + n, x - d) - a;
    int right = upper_bound(a, a + n, x + d) - a;
    return right - left;
}

int find_kth_distance(int x, int k) {
    int left = 0;
    int right = 2e8 + 9;
    int ans = right;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = count_within(x, mid);
        if (cnt >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int x, k;
        cin >> x >> k;
        cout << find_kth_distance(x, k) << '\n';
    }

    return 0;
}