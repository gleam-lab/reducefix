#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, sum, cnt, a[N];

void solve() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    while (m--) {
        cin >> x >> y;
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2;
            int pos = upper_bound(a + 1, a + n + 1, y + mid) - a;
            if (pos >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }
}

int main() {
    solve();
    return 0;
}