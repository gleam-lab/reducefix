#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N], b[N];

bool check(int mid, int x, int y, int k) {
    // The corrected check function should return true if there are at least k points from `A` within the range [mid - x, mid + x]
    // This is a placeholder function; actual implementation should be done accordingly.
    return true; // Placeholder, replace with actual implementation
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n); // Sort the array A
    for (int j = 0; j < q; j++) {
        int x, y;
        cin >> x >> y;
        int left = 0, right = 1e8;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, x, y, b[j])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Output the distance between the k-th closest point in A to B_j and B_j
        cout << abs(a[b[j]] - x) << endl;
    }
    return 0;
}