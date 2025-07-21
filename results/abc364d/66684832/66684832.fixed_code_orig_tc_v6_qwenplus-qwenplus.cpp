#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int n, q;
int a[200005];
vector<int> sorted_a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    sorted_a.assign(a, a + n);

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on answer: smallest distance d such that there are at least k points in A within distance d of b
        int left = 0, right = 2e8;
        while (left < right) {
            int mid = (left + right) / 2;
            int l = lower_bound(sorted_a.begin(), sorted_a.end(), b - mid) - sorted_a.begin();
            int r = upper_bound(sorted_a.begin(), sorted_a.end(), b + mid) - sorted_a.begin();
            if (r - l >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << "\n";
    }

    return 0;
}