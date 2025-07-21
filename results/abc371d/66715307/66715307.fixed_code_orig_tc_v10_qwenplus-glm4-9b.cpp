#include <bits/stdc++.h>
using namespace std;
int n, x[200050], p[200050], a[200050];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    a[0] = 0;  // Initialize the prefix sum array
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + p[i];  // Correct the prefix sum calculation
    }
    cin >> n;  // Correct the second n to q
    for (int q = 0; q < n; q++) {  // Correct the loop to iterate over the number of queries q
        int l, r; cin >> l >> r;
        int l1 = 1, r1 = n, l2 = 1, r2 = 1;
        while (l1 < r1) {  // Correct the condition for l1 and r1
            int mid = l1 + (r1 - l1) / 2;
            if (x[mid] >= l) r1 = mid;
            else l1 = mid + 1;
        }
        while (l2 < r2) {  // Correct the condition for l2 and r2
            int mid = l2 + (r2 - l2 + 1) / 2;
            if (x[mid] <= r) l2 = mid;
            else r2 = mid - 1;
        }
        cout << a[r2] - a[l1 - 1] << endl;  // Adjust the indices for the correct indices
    }
    return 0;
}