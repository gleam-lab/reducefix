#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int findFirstGreaterOrEqual(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int findFirstLessOrEqual(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1); // Sort the array to use binary search
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int l1 = findFirstGreaterOrEqual(x, n, l);
        int r1 = findFirstLessOrEqual(x, n, r);
        cout << a[r1] - a[l1 - 1] << endl;
    }
    return 0;
}