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
        int L, R;
        cin >> L >> R;
        
        // Find the index just after the last element less than L
        auto it1 = upper_bound(x, x + n + 1, L);
        // Find the index just before the first element greater than R
        auto it2 = lower_bound(x, x + n + 1, R + 1);

        int l = it1 - x - 1;
        int r = it2 - x - 1;

        if (l == -1 || r == n) { 
            cout << 0 << endl; 
        } else {
            cout << sum[r] - sum[l] << endl;
        }
    }
    return 0;
}