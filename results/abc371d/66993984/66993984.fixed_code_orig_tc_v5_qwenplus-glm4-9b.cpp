#include<bits/stdc++.h>
using namespace std;

int n, q;
int x[200005], p[200005];
long long sum[200005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    sum[0] = 0; // Initialize sum[0] to 0 to represent the sum of an empty subarray
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        // The problem statement mentions that we need to calculate the prefix sum of the array p
        // However, prefix sum is used here for the array x
        sum[i] = sum[i - 1] + x[i];
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        // Lower and upper bounds should be calculated based on array x, not p
        int lower_bound = lower_bound(x + 1, x + n + 1, L) - x;
        int upper_bound = upper_bound(x + 1, x + n + 1, R) - x;
        long long result = sum[upper_bound - 1] - (lower_bound == 0 ? 0 : sum[lower_bound - 1]);
        cout << result << endl;
    }
    return 0;
}