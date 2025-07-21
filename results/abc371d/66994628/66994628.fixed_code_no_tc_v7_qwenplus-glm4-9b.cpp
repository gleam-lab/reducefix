#include<bits/stdc++.h>
using namespace std;
int n, q;
int x[200005], p[200005];
long long sum[2000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum[i + 1] = sum[i] + p[i];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Ensure the bounds are within the range of x array
        l = max(l, x[0]);
        r = min(r, x[n - 1]);
        
        // Use upper and lower bounds to find the indices
        auto lb = lower_bound(x + 1, x + n + 1, l) - x - 1;
        auto ub = upper_bound(x + 1, x + n + 1, r) - x - 1;
        
        // Calculate the sum using the prefix sums array
        if (lb >= 0) {
            cout << sum[ub] - sum[lb] << endl;
        } else {
            cout << sum[ub] << endl;
        }
    }
    return 0;
}