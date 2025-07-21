#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1); // Sorting is necessary for binary search
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int index_l = binarySearch(x, n, l);
        int index_r = binarySearch(x, n, r);
        if (index_l == -1 || index_r == -1) cout << "0" << endl; // Handle out of range queries
        else cout << a[index_r] - a[index_l] << endl;
    }
    return 0;
}