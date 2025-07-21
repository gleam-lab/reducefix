#include <bits/stdc++.h>
#include <array>
#define endl "\n"
using namespace std;

const int N = 100000 + 5;
int a[N], d[N];

bool check(int mid, int x) {
    return d[min(N - 5, x + mid)] - d[max(0, x - mid - 1)] >= 10;
}

void solve(void) {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        for (int j = -10; j <= 10; j++) {
            if (x + j < 0 || x + j >= N) continue;
            a[x + j]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        int l = 0, r = 100000;
        while (r > l) {
            int mid = l + r + 1;
            if (check(mid, x)) r = mid - 1;
            else l = mid;
        }
        cout << l << endl;
    }
}

int main() {
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}