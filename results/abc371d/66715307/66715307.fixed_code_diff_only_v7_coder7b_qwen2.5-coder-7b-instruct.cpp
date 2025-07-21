#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;

int n, x[MAXN], p[MAXN], q, a[MAXN];

int binarySearchLeft(int target) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (x[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int binarySearchRight(int target) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (x[mid] <= target) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    sort(x + 1, x + n + 1); // Sort the array to use binary search effectively

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = a[i - 1] + p[i];
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        int leftIndex = binarySearchLeft(l);
        int rightIndex = binarySearchRight(r);
        cout << a[rightIndex] - a[leftIndex - 1] << endl;
    }

    return 0;
}