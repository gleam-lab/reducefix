#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N], b[N], k[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= q; ++i) {
        int lb = 0, ub = b[i], mid, lo = 0, hi = n, bestDist = INT_MAX;
        while (hi - lo > 1) {
            mid = (hi + lo) / 2;
            if (a[mid] <= b[i]) {
                lo = mid;
            } else {
                hi = mid;
            }
            if (a[lo] == b[i]) {
                bestDist = a[lo];
                break;
            }
        }
        if (lo < n && hi > 0) {
            int dist1 = abs(a[lo] - b[i]);
            int dist2 = (a[hi] <= b[i] + 100000000 ? INT_MAX : abs(a[hi] - b[i]));
            for (int j = lo; j <= hi - 1; ++j) {
                int dist = abs(a[j + 1] - b[i]);
                if (dist < bestDist) {
                    bestDist = dist;
                    k[i] = j + 1;
                }
            }
        }
        cout << bestDist << '\n';
    }
    return 0;
}