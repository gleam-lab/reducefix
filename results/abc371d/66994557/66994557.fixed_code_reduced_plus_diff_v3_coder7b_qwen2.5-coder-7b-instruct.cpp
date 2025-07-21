#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<long long> x(MAXN), p(MAXN);
vector<long long> sum(MAXN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    
    // Read input arrays
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> p[i];
    }

    // Calculate prefix sums
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + p[i];
    }

    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Adjust indices for zero-based indexing
        L--;
        R--;

        // Output the result of the range sum query
        cout << sum[R + 1] - sum[L] << endl;
    }

    return 0;
}