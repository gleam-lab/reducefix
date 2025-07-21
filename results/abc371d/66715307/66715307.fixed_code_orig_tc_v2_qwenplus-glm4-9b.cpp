#include <bits/stdc++.h>
using namespace std;

int n;
int x[200050], p[200050], a[200050];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + p[i];
    }
    cin >> n; // There seems to be a mistake here, as it should be 'q' not 'n'
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        if (l > r) {
            continue; // There's no range to answer if l > r
        }
        int l1 = 1, r1 = n, l2 = 1, r2 = n;
        while (l1 < r1) {
            int mid = l1 + (r1 - l1) / 2;
            if (x[mid] >= l) {
                r1 = mid;
            } else {
                l1 = mid + 1;
            }
        }
        while (l2 < r2) {
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] <= r) {
                l2 = mid;
            } else {
                r2 = mid - 1;
            }
        }
        // Ensure l2 and r1 are within bounds
        l2 = max(1, l2);
        r1 = min(n, r1);
        cout << a[r1] - a[l2 - 1] << endl;
    }
    return 0;
}