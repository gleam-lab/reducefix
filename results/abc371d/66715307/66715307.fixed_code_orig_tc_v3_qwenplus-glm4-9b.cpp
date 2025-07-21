#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, x[200050], p[200050], a[200050];

int binarySearch(int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (x[mid] >= target) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }
    cin >> n; // There was a typo, 'q' should be 'n' (the number of queries)
    while (n--) {
        int l, r; cin >> l >> r;
        int l1 = binarySearch(1, n, l);
        int l2 = binarySearch(1, n, r + 1); // r + 1 because we are including the range up to 'r'
        cout << a[l2 - 1] - a[l1 - 1] << endl; // Corrected the calculation for a[l2] - a[l1 - 1]
    }
    return 0;
}