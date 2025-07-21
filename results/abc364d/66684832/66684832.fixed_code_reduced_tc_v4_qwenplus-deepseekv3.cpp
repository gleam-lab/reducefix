#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 9;
int n, q;
int a[N];

bool check(int pos, int d, int k) {
    int left = lower_bound(a + 1, a + n + 1, pos - d) - a;
    int right = upper_bound(a + 1, a + n + 1, pos + d) - a;
    return (right - left) >= k;
}

int find_kth_distance(int pos, int k) {
    int low = 0, high = 2e14;
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(pos, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << endl;
    }

    return 0;
}