#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n;
    vector<int> x(n + 1), p(n + 1);
    
    // Read input values
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // Compute prefix sums
    vector<long long> sum(n + 1);
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        
        // Adjust indices because arrays are 1-based
        --L;
        --R;
        
        // Calculate the sum in the range [L, R]
        long long result = sum[R] - sum[L];
        cout << result << '\n';
    }

    return 0;
}