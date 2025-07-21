#include <bits/stdc++.h>
using namespace std;

int n, x[200050], p[200050], q, a[200050];

// Function to find the first index greater than or equal to 'val'
int binarySearchFirst(int val, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (x[mid] >= val) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

// Function to find the last index less than or equal to 'val'
int binarySearchLast(int val, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (x[mid] <= val) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return end;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1); // Sort the array to use binary search
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int l1 = binarySearchFirst(l, 1, n);
        int r1 = binarySearchLast(r, 1, n);
        cout << a[r1] - a[l1 - 1] << endl;
    }
    return 0;
}