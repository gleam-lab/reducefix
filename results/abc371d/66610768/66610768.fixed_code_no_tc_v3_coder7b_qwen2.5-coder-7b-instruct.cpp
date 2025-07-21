#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;
vector<ll> prefix_sum(N, 0);

int main() {
    int n, q;
    cin >> n;
    vector<ll> x(n), p(n);
    
    // Read the positions and population of each village
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    // Calculate the prefix sum of populations
    for (int i = 0; i < n; ++i) {
        if (i > 0) prefix_sum[i] += prefix_sum[i - 1];
        prefix_sum[i] += p[i];
    }

    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Find the first index where position is greater than or equal to l
        auto it_l = lower_bound(x.begin(), x.end(), l);
        // Find the first index where position is greater than r
        auto it_r = upper_bound(x.begin(), x.end(), r);

        int idx_l = distance(x.begin(), it_l);
        int idx_r = distance(x.begin(), it_r);

        // Calculate the total number of villagers in the range [l, r]
        ll result = prefix_sum[idx_r - 1];
        if (idx_l > 0) result -= prefix_sum[idx_l - 1];

        cout << result << endl;
    }

    return 0;
}