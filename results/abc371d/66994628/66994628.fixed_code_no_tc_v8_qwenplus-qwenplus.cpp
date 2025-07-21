#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector<int> x(n+2), p(n+2);  // Use vector for cleaner management and add padding
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Prefix sum of p
    vector<int> prefix_sum(n+2, 0);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;

        // Find first index where x[i] >= l (using lower_bound)
        int left_idx = lower_bound(x.begin() + 1, x.begin() + n + 1, l) - x.begin();

        // Find first index where x[i] > r (using upper_bound)
        int right_idx = upper_bound(x.begin() + 1, x.begin() + n + 1, r) - x.begin() - 1;

        if(left_idx > right_idx) {
            cout << 0 << endl;
        } else {
            cout << prefix_sum[right_idx] - prefix_sum[left_idx - 1] << endl;
        }
    }

    return 0;
}