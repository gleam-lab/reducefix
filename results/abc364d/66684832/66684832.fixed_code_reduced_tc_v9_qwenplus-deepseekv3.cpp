#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'

const int N = 1e5 + 5;
int a[N];

int count_points(int pos, int dx, int n) {
    int left = pos - dx;
    int right = pos + dx;
    int l = lower_bound(a, a + n, left) - a;
    int r = upper_bound(a, a + n, right) - a;
    return r - l;
}

int find_kth_distance(int pos, int k, int n) {
    int low = 0;
    int high = 2e8; // Maximum possible distance
    int ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (count_points(pos, mid, n) >= k) {
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

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k, n) << endl;
    }

    return 0;
}