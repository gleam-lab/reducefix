#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], q, a[200050];

int lower_bound(int val) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x[mid] >= val) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int val) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (x[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int l1 = lower_bound(l);
        int l2 = upper_bound(r);
        if (l1 > l2) {
            cout << 0 << endl;
        } else {
            cout << a[l2] - a[l1 - 1] << endl;
        }
    }
    return 0;
}