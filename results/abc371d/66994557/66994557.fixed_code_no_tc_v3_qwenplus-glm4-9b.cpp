#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
int sum[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i];  // Update the index to i+1 since array sum starts indexing from 1
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        int l = lower_bound(x, x + n, L) - x;  // Use pointers directly in lower_bound
        int r = upper_bound(x, x + n, R) - x;  // Use pointers directly in upper_bound
        if (l == r || l == n) {  // If no elements are in the range, or range is not valid
            cout << 0 << endl;
        } else {
            cout << sum[r] - sum[l] << endl;  // sum[r] and sum[l] directly give the range sum
        }
    }
    return 0;
}