#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Adjust indices to be 0-based for easier handling with lower_bound
        l--;
        r--;
        // Find the range of indices that match the query bounds
        int left = lower_bound(x + 1, x + n + 1, l) - (x + 1);
        int right = upper_bound(x + 1, x + n + 1, r) - (x + 1) - 1;
        // Calculate the sum over the range
        cout << sum[right] - sum[left - 1] << endl;
    }
    return 0;
}