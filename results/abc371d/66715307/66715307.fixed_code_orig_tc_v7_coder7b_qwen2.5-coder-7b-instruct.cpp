#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int binarySearchLeft(int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (x[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return left;
}

int binarySearchRight(int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (x[mid] <= target) left = mid;
        else right = mid - 1;
    }
    return left;
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
        int leftIndex = binarySearchLeft(1, n, l);
        int rightIndex = binarySearchRight(1, n, r);
        cout << a[rightIndex] - a[leftIndex - 1] << endl;
    }
    return 0;
}