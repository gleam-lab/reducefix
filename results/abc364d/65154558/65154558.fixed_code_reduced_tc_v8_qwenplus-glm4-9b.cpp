#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 200000000;
int a[N + 1];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ans(q);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x] = i + 1;  // Store the index in the array a corresponding to the x-coordinate
    }
    for (int i = 0; i < q; ++i) {
        int x, k; cin >> x >> k;
        int l = -100000000, r = 100000000;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            int count = 0, last = -1;
            for (int j = 0; j <= n; ++j) {
                if (a[mid + j] && a[mid + j] - a[last] >= k) {
                    count++;
                    last = a[mid + j];
                    if (count == k) {
                        ans[i] = last - mid;
                        break;
                    }
                }
            }
            if (count < k) {
                l = mid;  // The k-th closest point is further to the left
            } else {
                r = mid - 1;  // The k-th closest point is on the right or at mid
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}