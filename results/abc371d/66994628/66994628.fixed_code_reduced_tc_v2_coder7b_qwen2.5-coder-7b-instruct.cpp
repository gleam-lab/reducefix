#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> x(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Find the indices where l and r would be inserted if they were in the sorted list of x
        auto it_l = lower_bound(begin(x), end(x), l);
        auto it_r = upper_bound(begin(x), end(x), r);

        // Calculate the range sum using the prefix sums
        int idx_l = distance(begin(x), it_l);
        int idx_r = distance(begin(x), it_r);
        
        // If the right bound is just beyond the last element, adjust it
        if (it_r == end(x)) --idx_r;

        long long result = prefix_sum[idx_r] - prefix_sum[idx_l];
        cout << result << endl;
    }

    return 0;
}