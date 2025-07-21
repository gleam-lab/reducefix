#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int binarySearchLeft(int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int binarySearchRight(int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        int l1 = binarySearchLeft(l), r1 = binarySearchRight(r);
        cout << a[r1] - a[l1 - 1] << endl;
    }
    return 0;
}