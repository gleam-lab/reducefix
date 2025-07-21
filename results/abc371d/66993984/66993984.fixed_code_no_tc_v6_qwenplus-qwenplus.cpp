#include<bits/stdc++.h>
using namespace std;

int n, q, x[200005], p[200005];
long long prefix_sum[200005];  // Use long long to avoid integer overflow

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;

        // Find first index where x[i] >= L
        int left = lower_bound(x + 1, x + n + 1, L) - x;
        // Find first index where x[i] > R
        int right = upper_bound(x + 1, x + n + 1, R) - x - 1;

        if (left > right) {
            cout << 0 << endl;
        } else {
            cout << prefix_sum[right] - prefix_sum[left - 1] << endl;
        }
    }

    return 0;
}